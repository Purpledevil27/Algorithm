// Time Complexity: O(N2)
// Auxiliary Space: O(1)

/*
Bubble Sort is the simplest sorting algorithm
that works by repeatedly swapping the adjacent elements
if they are in the wrong order.
*/

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &v)
{
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
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
    bubbleSort(v);

    for (auto &i : v)
    {
        cout << i << " ";
    }

    return 0;
}
