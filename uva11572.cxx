// By Patricio Palma Contreras <patriciop@gmail.com>
// 2018
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

// #include "mydebug.h"

using namespace std;

int main()
{
    int noTestCases;
    cin >> noTestCases;
    while (noTestCases--) {

        map<int, int> flakesPos;
        size_t maxBagSize = 0;
        int noSnowFlakes;
        cin >> noSnowFlakes;
        size_t fPrevPos = 0, i = 1;
        for (; i<=noSnowFlakes; ++i) {

            int flake;
            cin >> flake;

            // if the current read flake is already present and it is located
            // after the previous mark, then update the max and mark.
            if( flakesPos.count(flake)!=0 && flakesPos[flake]>fPrevPos) {
                maxBagSize = max(maxBagSize, i-1 - fPrevPos);
                fPrevPos = flakesPos[flake];
            }
            // update current flake position.
            flakesPos[flake] = i;

            // println("i=",i,"x=",flake,"u=",fPrevPos,"mx=",maxBagSize , flakesPos);
        }
        maxBagSize = max(maxBagSize, noSnowFlakes-fPrevPos);
        // println("i=",i,"x=",-1,"u=",fPrevPos,"mx=",maxBagSize , flakesPos);

        cout << maxBagSize << '\n';
    }
    return 0;
}