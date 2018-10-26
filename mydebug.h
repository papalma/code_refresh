#ifndef MY_CUSTOM_DEBUG_PRINT
#define MY_CUSTOM_DEBUG_PRINT

#include <iostream>

namespace std {

template<typename T>
void println(const T& t) 
{
    cout << t << '\n';
}

template<typename T, typename... Args>
void println(const T& t, Args... args)
{
    cout << t << ' ';
    println(args...);
}

template<typename T, typename U>
ostream& operator<<(ostream& os, const pair<T,U>& t) 
{
    os << '(' << t.first << ',' << t.second << ')';
    return os;
}

// this should match most common containers
template<template <typename...> class C, typename... Ts>
ostream& operator<<(ostream& os, const C<Ts...>& v) 
{
    os << "[";
    bool first = true;
    for(auto e : v) {
        if(!first) cout << ',';
        first = false;
        os << e;
    }
    os << "]";
    return os;
}

} // end namespace
#endif