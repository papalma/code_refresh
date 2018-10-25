#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>

using namespace std;

template<typename T>
void println(const T& t) 
{
    cout << t << '\n';
}

template<typename T, typename... Args>
void println(const T& t, Args... args)
{
    cout << t << ' ';
    println(args...);
}

struct Info {
    Info(const string& t, const string& d, int k) :
        timestamp(t), direction(d), km(k) { }
    string timestamp;
    string direction;
    int km;
};

template<> struct std::less<Info>{
    bool operator()(const Info& a, const Info& b) const {
        if(a.timestamp == b.timestamp) {
            return a.direction < b.direction;
        }
        return a.timestamp < b.timestamp;
    }
};
using PlateInfo = map<string,set<Info>>;

vector<int> readFares(const string& text ) 
{
    // read fares from text
    vector<int> fare;
    istringstream iss(text);
    int i;
    while(iss >> i) {
        fare.push_back(i);
    }
    return fare;
}

void readPlateInfo( const vector<string>& platesText, PlateInfo& plateInfo )
{
    for( auto line : platesText) {
        string plate, timestamp, direction;
        int km;

        istringstream iss(line);
        iss >> plate >> timestamp >> direction >> km;
        // println(plate, timestamp);
        plateInfo[plate].insert(Info(timestamp, direction, km));
    }
}

double calculateBill(const string& plate, const set<Info>& infoSet, const vector<int>& fares)
{
    double amount = 0.0;

    auto end = infoSet.cend();
    for ( auto it = infoSet.cbegin(); it != end;) {
        auto info1 = it++;
        if( info1->direction == "enter" ) {
            if(it != end && it->direction == "exit") {
                double fare = fares[stoi(info1->timestamp.substr(6,2))];
                amount += 1.0 + abs(it->km - info1->km)*fare/100;
                it++;
            }
        }
    }

    return amount > 0.0 ? amount + 2 : 0;
}

void process(const string& lineFare, const vector<string>& platesText)
{
    auto fares = readFares(lineFare);
    PlateInfo plateInfo;
    readPlateInfo(platesText, plateInfo);

    for(auto e : plateInfo) {
        auto bill = calculateBill(e.first, e.second, fares);
        if(bill > 0.0)
            printf("%s $%.2f\n", e.first.c_str(), bill );
    }
}

int main()
{
    int n;
    cin >> n;
    string line;
    getline(cin, line);
    getline(cin, line);

    while (n--) {
        vector<string> linePlates;

        string lineFare;
        getline(cin, lineFare);

        // read plates until blank line or eof
        while (getline(cin, line)) {
            if (line.empty())
                break;
            linePlates.push_back(line);
        }

        process(lineFare, linePlates);
        if(n>0) println("");
    }
}