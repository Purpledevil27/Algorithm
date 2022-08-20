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
        int height = (int)ceil(log(n) / log(2));
        int size = pow(2, height + 1) - 1;
        segTree.resize(size);
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
            segTree[i] = segTree[2 * i]+ segTree[2 * i + 1];
        }
    }
    */
    void constructTree(vector<int> &nums, int low, int high, int pos)
    {
        if (low == high)
        {
            segTree[pos] = nums[low];
            return;
        }
        int mid = (low + high) / 2;
        constructTree(nums, low, mid, 2 * pos + 1);
        constructTree(nums, mid + 1, high, 2 * pos + 2);
        segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
    }

    int rangeSumQuery(int low, int high, int const &qlow, int const &qhigh, int pos)
    {
        if (qlow <= low && qhigh >= high)
        {
            return segTree[pos];
        }
        if (qlow > high || qhigh < low)
        {
            return 0;
        }
        int mid = (low + high) / 2;
        return rangeSumQuery(low, mid, qlow, qhigh, 2 * pos + 1) + rangeSumQuery(mid + 1, high, qlow, qhigh, 2 * pos + 2);
    }

    void update(int pos, int const &val, int const &qlow, int const &qhigh, int low, int high)
    {
        if (qlow <= low && qhigh >= high)
        {
            segTree[pos] = val;
            return;
        }
        if (qlow > high || qhigh < low)
        {
            return;
        }
        int mid = (low + high) / 2;
        update(2 * pos + 1, val, qlow, qhigh, low, mid);
        update(2 * pos + 2, val, qlow, qhigh, mid+1, high);
        segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
    }

public:
    int rangeSumQuery(int const &l, int const &r)
    {
        return rangeSumQuery(0, n - 1, l, r, 0);
    }

    void update(int const &index, int const &val)
    {
        update(0, val, index, index, 0, n - 1);
    }

    /*
    // Iterative update approach
    void update(int const &index, int const &val)
    {
        segTree[index + n] = val;
        for (int i = (index + n) / 2; i >= 1; i /= 2)
        {
            segTree[i] = segTree[2 * i] + segTree[2 * i + 1];
        }
    }
    */
};

int main()
{
    vector<int> v = {1, 3, 9, 0, -1, 4, 5};
    SegmentTree s(v);
    cout << s.rangeSumQuery(0, 1) << endl;
    cout << s.rangeSumQuery(3, 6) << endl;
    cout << s.rangeSumQuery(4, 5) << endl;
    cout << s.rangeSumQuery(1, 3) << endl;
    cout << s.rangeSumQuery(0, 4) << endl;
    s.update(6, 0);
    cout << s.rangeSumQuery(3, 3) << endl;
    cout << s.rangeSumQuery(0, 1) << endl;
    cout << s.rangeSumQuery(5, 6) << endl;
    cout << s.rangeSumQuery(4, 5) << endl;
    cout << s.rangeSumQuery(1, 3) << endl;
    cout << s.rangeSumQuery(6, 6) << endl;
    return 0;
}