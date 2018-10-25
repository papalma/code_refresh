#include <iostream>
// #include <unordered_map>
#include <map>

using namespace std;

template<typename T>
void println(const T& t)
{
    std::cout << t << '\n';
}

template<typename T, typename... Args>
void println(const T& t, Args... args) {
    std::cout << t << ' ';
    println(args...);
}

int main()
{
    int n;
    scanf("%d\n\n", &n);
    while( n-- ) {
        string line;
        map<string, int> table;
        int counter = 0;

        while(getline(cin, line)) {
            if(line.empty()) break;
            counter++;
            table[line]++;
        }

        for(auto i : table) {
            printf("%s %.4f\n", i.first.c_str(), double(i.second)/counter*100);
        }

        if(n>0) {
            cout << '\n';
        }
    }
    return 0;
}