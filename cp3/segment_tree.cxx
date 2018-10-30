// By Patricio Palma Contreras <patriciop@gmail.com> 
// Santiago 2018
#include <iostream>
#include <vector>
#include "../mydebug.h"

using namespace std;

struct SegmentTree {
    vector<int> st, A;
    int n;
    int left(int p) { return p << 1; }
    int right(int p) { return (p << 1) +1; }

    void build(int p, int L, int R) {
        println("p=", p, "L=", L, "R=", R);
        if(L == R) {
            // leaf nodes contains it index (they are it's own mins)
            st[p] = L;
        }
        else {
            // non-lead nodes 
            build(left(p) ,  L         , (L+R)/2);
            build(right(p), (L+R)/2 + 1,  R);
            int p1 = st[left(p)];
            int p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }

    // p= start node, L,R= segment, i,j=search segment 
    int rmq(int p, int L, int R, int i, int j) {
        if(i>R || j<L) {
            println("discard p=",p,"L,R=",L,R,"i,j=",i,j); 
            return -1; // segment out of range
        }

        // if the current node range L-R is part of the range we are
        // looking for i-j get its max value index.
        if(L>=i && R <=j ) { 
            println("inside  query p=",p,"L,R=", L,R, "i,j=",i,j);
            return st[p]; // inside query
        } 
        println("outside query p=",p,"L,R=", L,R, "i,j=",i,j); 
        // look for the range i-j in on the left half and the in the right half
        int p1 = rmq(left(p),  L,         (L+R)/2, i, j);
        int p2 = rmq(right(p), (L+R)/2+1, R,       i, j);

        // if any search returned out of range, the rertun the other's index
        if(p1==-1) return p2;
        if(p2==-1) return p1;

        // else return the index of the minimum value;
        return A[p1] <= A[p2] ? p1 : p2;
    }

    int rmq(int i, int j) { cout << endl; return rmq(1, 0, n-1, i, j);}

    SegmentTree(const vector<int>& _A) : A(_A), n(_A.size()) {
        st.assign(4*n,0);
        build(1, 0, n-1);
        println("end building");
    }
};

int main()
{
    vector<int> A{ 18,17,13,19,15,11,20 };
    SegmentTree st(A);
    cout << "rmq(1,3)=" << st.rmq(1,3) << '\n'
         << "rmq(4,6)=" << st.rmq(4,6) << endl;
    return 0;
}