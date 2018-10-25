#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>
#include <sstream>
#include <algorithm>

#include <mydebug.cxx>

using namespace std;


struct CatCounter {
    string name;
    int matches;
    int atLeast;
    vector<string> keywords;
};

char filterText(const char c)
{
    // if(isalpha(c)) return tolower(c);
    if(isalpha(c)) return c;
    return ' ';
}

int main()
{
    // read test cases
    int N;
    cin >> N;
    while (N--) {
        unordered_map<string, shared_ptr<CatCounter>> categoryMap;

        // read C categories.
        int C;
        cin >> C;
        while (C--) {
            int noKey, noMatch;
            string name;

            cin >> name >> noKey >> noMatch;
            auto category = shared_ptr<CatCounter>(new CatCounter);
            category->name = name;
            category->atLeast = noMatch;

            while (noKey--) {
                string kw;
                cin >> kw;
                categoryMap[kw] = category;
                category->keywords.push_back(kw);
            }
            println("category:", name, noMatch);
            cout << category->keywords << '\n';
        }
        
        // read text
        bool first = true;
        string line;
        getline(cin,line);
        while(getline(cin,line)) {
            if(line.empty()) break;
            // get each word on the line
            transform(begin(line), end(line), begin(line), filterText);

            istringstream iss(line);
            string word;
            while(iss >> word) {
                println("reading: ", word);
                // words with no categories are skipped
                if( categoryMap.count(word) < 1 ) {
                    println("not registered");
                    continue;
                }

                auto category = categoryMap[word];
                category->matches++;
                println("incr cat:", word, category->matches);
                if( category->matches == category->atLeast ) {
                    if(first)
                        first = false;
                    else 
                        cout << ',';
                    cout << category->name;

                    // for( auto kw : category->keywords ) {
                    //     categoryMap.erase(kw);
                    // }
                }
            }
        }

        if(first)
            cout << "SQF Problem.";
        cout << endl;
    }
    // cout << '\n';
    return 0;
}
