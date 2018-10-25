#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <algorithm>

// #include "mydebug.cxx"

using namespace std;

struct Category {
    string name;
    int requiredMatches = 0;
    unordered_map<string, bool> keywordsFound;
};

char keepOnlyLetters(const char c)
{
    if(isalpha(c)) return c;
    return ' ';
}

int main()
{
    // read test cases
    int N;
    cin >> N;
    while (N--) {
        unordered_multimap<string, int> categoryMap;
        vector<Category> categoryVector;

        // read C categories.
        int C;
        cin >> C;
        while (C--) {

            string name;
            int noKey, requiredMatches;
            cin >> name >> noKey >> requiredMatches;

            // 
            unordered_set<string> keywords;
            while (noKey--) {
                string kw;
                cin >> kw;
                keywords.insert(kw);
            }

            Category category;
            category.name = name;
            category.requiredMatches = requiredMatches;
            categoryVector.push_back(category);

            // insert mapping kw->category
            for( auto kw : keywords ) {
                // println("inserting kw:cat =", kw, name);
                categoryMap.insert({kw, categoryVector.size()-1});
            }
        }
        
        // read text
        string line;
        getline(cin,line);
        while(getline(cin,line)) {

            if(line.empty()) break;
            // get each word on the line
            transform(begin(line), end(line), begin(line), keepOnlyLetters);

            istringstream iss(line);
            string word;
            while(iss >> word) {
                // println("reading: ", word);
                // words with no categories are skipped
                if( categoryMap.count(word) < 1 ) {
                    continue;
                }

                auto range = categoryMap.equal_range(word);
                for(auto it = range.first; it != range.second; it++) {
                    auto& category = categoryVector[it->second];
                    category.keywordsFound[word] = true;
                }
            }
        }
        
        int displayed = 0;
        for( auto c : categoryVector ) {
            int noFoundKeywords = 0;
            for( auto e : c.keywordsFound ) {
                noFoundKeywords += e.second ? 1 : 0;
            }
            if( noFoundKeywords >= c.requiredMatches ) {
                if(displayed>0) cout << ',';
                cout << c.name;
                ++displayed;
            }
        }

        if(displayed == 0)
            cout << "SQF Problem.";
        cout << endl;
    }
    return 0;
}
