// By Patricio Palma Contreras <patriciop@gmail.com>
// 2018

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
// #include <tuple>

#include "mydebug.h"

using namespace std;

// using Segment = pair<int, int>;

// map<int, int> flake;

// this are comparators for segment containers
// auto sortByStart = [](const Segment& lhs, const Segment& rhs)
// {
//     return lhs.first < rhs.first;
// };
// set<Segment, decltype(sortByStart)>  segmentsByStart(sortByStart);
// map<int, Segment> segmentsByStart;

// bool sortByEnd(const Segment& lhs, const Segment& rhs)
// {
//     return lhs.second < rhs.second;
// }
// set<Segment, bool(*)(const Segment&, const Segment&)>  segmentsByEnd(sortByEnd);
// map<int, Segment> segmentsByEnd;

// int slen(const Segment& s)
// {
//     return s.second - s.first;
// }

// bool isAinB(const Segment& a, const Segment& b)
// {
//     return b.first <= a.first && a.second <= b.second;
// }

set<int> flakes;

int main()
{
    int noTestCases;
    cin >> noTestCases;
    while (noTestCases--) {

        set<int> bag;
        size_t maxBagSize = 0;
        int noSnowFlakes;
        cin >> noSnowFlakes;
        int pos = 0;
        flakes.clear();
        int u = 0;
        for (; noSnowFlakes--; pos++) {
            int sf;
            cin >> sf;
            // println("read: ", sf, "current bag:", flakes);

            if( flakes.count(sf) == 0 ) {
                flakes.insert(sf);
                maxBagSize = max(flakes.size(), maxBagSize);
            }
            else {
                flakes.clear();
                flakes.insert(sf);
                maxBagSize = max(flakes.size(), maxBagSize);
                u=pos;
            }

            // if (flake.count(sf) == 0) {
            //     flake[sf] = pos;
            // } else {
            //     auto segment = make_pair(flake.at(sf), pos);
            //     flake[sf] = pos;
            //     segmentsByStart.insert({ segment.first, segment });
            //     segmentsByEnd.insert({ segment.second, segment });
            // }
            println("(sf,u,pos)=",sf,u,pos);
        }
        maxBagSize = max( maxBagSize, size_t(pos+1-(u-1));
        // println('-', "sByStart:", segmentsByStart);
        // println('-', "sByEnd  :", segmentsByEnd);
        // for (int i = 0; i < pos; i++) {
        //     if (segmentsByStart.count(i) == 0) {
        //         auto segment = make_pair(i, pos);
        //         segmentsByStart.insert({ segment.first, segment });
        //         segmentsByEnd.insert({ segment.second, segment });
        //     } else {
        //         println(i, "erasing on byEnd ");
        //         segmentsByEnd.erase(i);
        //     }

        //     println(i, "sByStart:", segmentsByStart);
        //     println(i, "sByEnd  :", segmentsByEnd);

        //     auto s1 = segmentsByStart[i];
        //     int len = slen(s1);
        //     if (begin(segmentsByEnd) != end(segmentsByEnd)) {
        //         auto s2 = begin(segmentsByEnd)->second;
        //         if (isAinB(s2, s1))
        //             len = s2.second - s1.first;
        //     }
        //     maxLen = max(len, maxLen);
        // }

        cout << maxBagSize << '\n';
    }
    return 0;
}