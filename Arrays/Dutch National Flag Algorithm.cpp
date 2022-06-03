// https://users.monash.edu/~lloyd/tildeAlgDS/Sort/Flag/

// For three colors or Sort 0 1 2 as red white blue
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int mid = 0, low = 0, high = n - 1;

        while (mid <= high)
        {
            if (nums[mid] == 2)
            {
                swap(nums[mid], nums[high]);
                high--;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else if (nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        v.push_back(k);
    }
    Solution obj;
    obj.sortColors(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}