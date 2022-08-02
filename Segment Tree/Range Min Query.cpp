// Implementation of Segment Tree for Range Min Query - Mutable problem

#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> segTree;
    int n;

public:
    SegmentTree(vector<int> &nums)
    {
        n = nums.size();
        // if input len is pow of 2 then size of segment tree is 2*len - 1,
        // otherwise size of segment tree is next (pow of 2 for len)*2 - 1.
        int height = (int)ceil(log(n) / log(2));
        int size = pow(2, height + 1) - 1;
        /*while (__builtin_popcount(n) != 1)
        {
            nums.push_back(0);
            n++;
        }
        segTree.resize(2 * n, INT_MAX);*/
        segTree.resize(size, INT_MAX);
        constructTree(nums, 0, n - 1, 0);
    }

private:
    /*
    // Construct tree iteratively
    void constructTree(vector<int> &nums, int low, int high, int pos) // O(N)
    {
        for (int i = 0; i < n; i++)
        {
            // we can prove (n+i)th element in tree = (i)th element in array by drawing a tree and indexing(1-indexed) it
            segTree[n + i] = nums[i];
        }

        for (int i = n-1; i >= 1; i--)
        {
            segTree[i] = min(segTree[2 * i], segTree[2 * i + 1]);
        }
    }
    */
    void constructTree(vector<int> &nums, int low, int high, int pos) // O(N)
    {
        if (low == high)
        {
            segTree[pos] = nums[low];
            return;
        }
        int mid = (low + high) / 2;
        constructTree(nums, low, mid, 2 * pos + 1);
        constructTree(nums, mid + 1, high, 2 * pos + 2);
        segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
    }

    int rangeMinQuery(int const &qlow, int const &qhigh, int low, int high, int pos) // O(log(N))
    {
        if (qlow <= low && qhigh >= high)
        {
            return segTree[pos];
        }
        if (qlow > high || qhigh < low)
        {
            return INT_MAX;
        }
        int mid = (low + high) / 2;
        return min(rangeMinQuery(qlow, qhigh, low, mid, 2 * pos + 1), rangeMinQuery(qlow, qhigh, mid + 1, high, 2 * pos + 2));
    }

public:
    int rangeMinQuery(int const &l, int const &r)
    {
        return rangeMinQuery(l, r, 0, n - 1, 0);
    }

private:
    void update(int i, int const &val, int const &qlow, int const &qhigh, int low, int high) // O(log(N))
    {
        if (qlow <= low && qhigh >= high)
        {
            // Leaf Node
            segTree[i] = val;
            return;
        }
        if (qlow > high || qhigh < low)
        {
            return;
        }
        int mid = (low + high) / 2;
        update(2 * i + 1, val, qlow, qhigh, low, mid);
        update(2 * i + 2, val, qlow, qhigh, mid + 1, high);
        segTree[i] = min(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

public:
    // Update recursive approach
    void update(int const &index, int const &val)
    {
        // 0 is the root here
        update(0, val, index, index, 0, n - 1);
    }
    /*
    // Iterative update approach - 1 indexed
    void update(int const &index, int const &val)
    {
        segTree[index + n] = val;
        for (int i = (index + n) / 2; i >= 1; i /= 2)
        {
            segTree[i] = min(segTree[2 * i], segTree[2 * i + 1]);
        }
    }
    */
};

int main()
{
    vector<int> v = {1, 3, 9, 0, -1, 4, 5};
    SegmentTree s(v);
    cout << s.rangeMinQuery(0, 1) << endl;
    cout << s.rangeMinQuery(3, 6) << endl;
    cout << s.rangeMinQuery(4, 5) << endl;
    cout << s.rangeMinQuery(1, 3) << endl;
    cout << s.rangeMinQuery(0, 4) << endl;
    s.update(6, 0);
    cout << s.rangeMinQuery(3, 3) << endl;
    cout << s.rangeMinQuery(0, 1) << endl;
    cout << s.rangeMinQuery(5, 6) << endl;
    cout << s.rangeMinQuery(4, 5) << endl;
    cout << s.rangeMinQuery(1, 3) << endl;
    cout << s.rangeMinQuery(6, 6) << endl;
    return 0;
}