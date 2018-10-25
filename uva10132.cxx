#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> parts;
unordered_map<string,int> freq;

int main() 
{
    int n;
    cin >> n;
    string line;
    getline(cin, line); 
    getline(cin, line);
    while(n--) {

        while(getline(cin,line)) {
            // cout << "n="<<n<< " line="<<line << endl;
            if(line.empty()) break;
            parts.push_back(line);
        }

        // generates a frequency table for pieces form by two differente pieces
        for(int i=0; i<parts.size() ; i++) {
            for(int j=0; j<parts.size(); j++) {
                if( i == j ) continue;
                freq[parts[i]+parts[j]]++;
            }
        }

        // lookup for the high freq in the table
        unordered_map<string,int>::const_iterator max = freq.cbegin();
        for(auto it = freq.cbegin(); it != freq.cend(); it++) {
            if(max->second < it->second) {
                max = it;
            }
        }

        cout << max->first << '\n';
        if(n>0) cout << '\n';

        parts.clear();
        freq.clear();

    }
    return 0;
}