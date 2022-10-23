// Time Complexity - O(N^2)
// Space Complexity - O(1)

/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element
(considering ascending order) from the unsorted part and putting it at the beginning.
*/

// Not a stable sorting algorithm but can be made stable
// if the minimum element is put on the right place
// and just sliding the remaining element by 1

#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &v)
{
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        int m = v[i], min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (m > v[j])
            {
                m = v[j];
                min_index = j;
            }
        }
        swap(v[i], v[min_index]);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    selectionSort(v);
    for (auto &i : v)
    {
        cout << i << " ";
    }
    return 0;
}
