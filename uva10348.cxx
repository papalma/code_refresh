#include <iostream>

#include "mydebug.h"

using namespace std;

void readSub() 
{
    int x1, x2, y1,y2;
    scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2);
    //
}

void readPoly()
{
    int noPoints;
    cin >> noPoints;
    while(--noPoints) {
        int x, y;
        cin >> x >> y;
    }
}

int main()
{
    int noSubs;
    cin >> noSubs;
    while(noSubs--) {
        readSub();
    }
    return 0;
}