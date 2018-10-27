/* UVA 417 */

#include <iostream>
#include <unordered_map>
#include <queue>

#include "mydebug.h"

using namespace std;

unordered_map<string, int> map;

// this will construct all valid strings, based on previous valid strings.
void generate() {
    queue<string> q;
    for(char c='a'; c<='z'; ++c) {
        q.push(string(1,c));
    }

    // iterate the queue to fill the map and construct the rest of strings.
    int count = 1;
    while(!q.empty()) {
        string s = q.front();
        q.pop();

        map[s] = count++;

        // while s.length()<5 then generate all valid strings with 
        // lenght+1 starting with s
        for(char c = s.back() + 1; s.length() < 5 && c <= 'z'; ++c) {
            q.push(s+c);
        }
    }
}


int main()
{
    generate();
    string s;
    while(cin >> s) {
        cout << (map.count(s) ? map[s] : 0) << '\n';
    }
    return 0;
}
