// From book "Competitive Programming 3" by Steve and Felix Halim.

#include <iostream>
#include <vector>

class SegmentTree
{
  private:
    std::vector<int> st, A;
    int n;

    // P's child nodes
    int left(int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }

    void build(int p, int L, int R)
    {
        if (L == R)
            st[p] = L;
        else
        {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)];
            int p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }

    int rmq(int p, int L, int R, int i, int j)
    {
        if (i > R || j < L)
            return -1;        // current segment outside query range
        if (L >= i && R <= j) // current segment inside query range
            return st[p];

        // compute the min pos in the left and right part of the traversal
        int p1 = rmq(left(p), L, (L + R) / 2, i, j);
        int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

        if (p1 == -1)
            return p2; // segment outside query range
        if (p2 == -1)
            return p1;

        return A[p1] <= A[p2] ? p1 : p2;
    }

  public:
    SegmentTree(const std::vector<int> &_A)
    {
        A = _A;
        n = (int)A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int rmq(int i, int j)
    {
        return rmq(1, 0, n - 1, i, j);
    }
};

int main(int argc, char **argv)
{
    std::vector<int> v{18, 17, 13, 19, 15, 11, 20};
    SegmentTree segmentTree(v);
    std::cout << "RMQ(1,3)=" << segmentTree.rmq(1, 3) << "\n";
    std::cout << "RMQ(4,6)=" << segmentTree.rmq(4, 6) << "\n";
}