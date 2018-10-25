#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <sstream>

// #include "mydebug.cxx"

using namespace std;


int main()
{
    int n;
    while(cin >> n && n > 0) {
        // vector<set<int>> froshes;
        unordered_map<string,int> coursesFreq;
        while(n--) {
            int c1,c2,c3,c4,c5;
            scanf("%d %d %d %d %d\n", &c1, &c2, &c3, &c4, &c5);
            set<int> froshCourses = { c1,c2,c3,c4,c5 };

            ostringstream oss;
            for(auto c : froshCourses) {
                oss << c;
            }
            // println(oss.str());
            coursesFreq[oss.str()]++;
        }

        // look for the max
        auto itToMax = coursesFreq.cbegin();
        for( auto it = coursesFreq.cbegin(); it != coursesFreq.end();  it++ ) {
            // println("max:", itToMax->second, "curr elem:", it->first, it->second);
            if(itToMax->second < it->second) {
                itToMax = it;
            }
        }
        // println("it max:", itToMax->second);

        // count winners
        int winners = 0;
        for(auto k : coursesFreq ) {
            if( k.second < itToMax->second ) continue;
            winners += k.second;
        }
        cout << winners << endl;
    }

    return 0;
}