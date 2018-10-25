// By Patricio Palma Contreras <patriciop@gmail.com>
// 2018

// TODO: not passing

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

void registerStampData(set<int>& uniqueStampsSet, const set<int>& stampTypes)
{
    // if stamp is not unique then remove it
    for(auto s : stampTypes) {
        if(uniqueStampsSet.count(s)>0) {
            uniqueStampsSet.erase(s);
        }
        else {
            uniqueStampsSet.insert(s);
        }
    }
}

int countUniqueStamps(
        const set<int>& friendData, 
        const unordered_map<int,int>& stampTypeCount, 
        const set<int>& uniqueStampsSet)
{
    int count = 0;
    for( auto st : friendData) {
        if( uniqueStampsSet.count(st) > 0) {
            // count += stampTypeCount.at(st);
            count++;
        }
    }
    return count;
}

int countTotalUniqueStamps(
        const unordered_map<int,int>& stampTypeCount, 
        const set<int>& uniqueStamps)
{
    int count = 0;
    for(auto s : uniqueStamps) {
        count += stampTypeCount.at(s);
    }
    return count;
}

void process()
{
    static int processCount = 1;
    vector<set<int>> friendsData;
    unordered_map<int,int> stampTypeCount;
    set<int> uniqueStampsSet;

    // load data
    int noFriends;
    cin >> noFriends;
    while( noFriends-- ) {
        set<int> stampsData;
        int noStamps;
        cin >> noStamps;
        while( noStamps-- ) {
            int stampType;
            cin >> stampType;
            stampsData.insert(stampType);
            stampTypeCount[stampType]++;
        }
        registerStampData(uniqueStampsSet, stampsData);
        friendsData.push_back(stampsData);
    }
    if(processCount>1) cout << '\n';
    printf("Case %d: ", processCount++);
    // const int totalUniqueStamps = countTotalUniqueStamps(stampTypeCount, uniqueStampsSet);
    const int totalUniqueStamps = uniqueStampsSet.size();
    // cout << "totalUnique: " << totalUniqueStamps << endl;

    if(!uniqueStampsSet.empty())
        for(int i=0; i<friendsData.size(); i++) {
            if(i!=0) cout << ' ';
            printf("%.6f%%", 100.0 * countUniqueStamps(
                friendsData[i], stampTypeCount, uniqueStampsSet)/totalUniqueStamps);
            // printf("%d", countUniqueStamps(
            //     friendsData[i], stampTypeCount, uniqueStampsSet));
        }
    // cout << endl;
}

int main()
{
    int noTestCases;
    cin >> noTestCases;
    while( noTestCases-- ) {
        process();
    }
    return 0;
}