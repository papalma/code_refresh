#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, int> table;
vector<int> nos;

int main() {
    int no = 0;

    while(cin >> no) {
        if(!table.count(no)) {
            nos.push_back(no);
        }
        table[no]++;
    }
    for(auto e : nos) {
        cout << e << ' ' << table[e] << '\n';
    }
    return 0;
} 