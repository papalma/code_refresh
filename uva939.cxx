#include <iostream>
#include <map>
#include <set>

using namespace std;

multimap<string, string> childParent;
map<string, string> peopleInfo;
set<string> people;

const string NON_EXISTENT = "non-existent";
const string DOMINANT = "dominant";
const string RECESSIVE = "recessive";

// these are defined in the problem statement
bool isPresent(const string& a, const string& b)
{
    return (a != NON_EXISTENT && b != NON_EXISTENT) ||
            (a == DOMINANT && b != DOMINANT) || 
            (a != DOMINANT && b == DOMINANT);
}

bool isDominant(const string& a, const string& b)
{
    return (a == DOMINANT && b == DOMINANT) || 
            (a == DOMINANT && b == RECESSIVE) || 
            (a == RECESSIVE && b == DOMINANT);
}

// get peoplo gene info, if not available it recurses  to parent info
string getPeopleInfo(const string& name)
{
    if (peopleInfo[name].empty()) {

        auto range = childParent.equal_range(name);
        auto it = range.first;
        string info1 = getPeopleInfo(it->second);
        it++;
        string info2 = getPeopleInfo(it->second);

        // generate info based on problem statement
        if (!isPresent(info1, info2)) {
            return NON_EXISTENT;
        }
        if (isDominant(info1, info2)) {
            return DOMINANT;
        }
        return RECESSIVE;
    }
    return peopleInfo[name];
}

int main()
{
    int n;
    cin >> n;
    while (n--) {
        string who, data;
        cin >> who >> data;
        if (data == NON_EXISTENT || data == RECESSIVE || data == DOMINANT) {
            peopleInfo[who] = data;
        } else {
            childParent.insert({ data, who });
            people.insert(data);
        }
        people.insert(who);
    }

    // people's set avoids merging and sorting keys from both maps.
    for (auto k : people) {
        cout << k << ' ' << getPeopleInfo(k) << '\n';
    }
    return 0;
}