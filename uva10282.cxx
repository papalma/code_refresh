#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

int main()
{
    string line;
    unordered_map<string,string> dict;
    istringstream iss;

    // dictionary definition
    while(getline(cin, line) ) {
        if( line.empty() ) break;
        iss.str(line);
        iss.clear();

        string meaning, word;
        iss >> meaning >> word;
        dict[word] = meaning;
    }

    // this works in case a message line contains multiple words
    // while(getline(cin,line)) {
    //     iss.str(line);
    //     iss.clear();

    //     string word;
    //     bool first = true;
    //     while(iss >> word) {
    //         if(first) {
    //             first = false;
    //         }
    //         else {
    //             cout << ' ';
    //         }
    //         cout << ( dict.count(word)>0 ? dict[word] : "eh");
    //     }
    //     cout << '\n';
    // }

    while(getline(cin,line)) {
        cout << ( dict.count(line)>0 ? dict[line] : "eh") << '\n';
    }

    return 0;
}