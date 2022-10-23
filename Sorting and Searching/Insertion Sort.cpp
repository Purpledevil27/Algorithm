// Time Complexity: O(N^2)
// Auxiliary Space: O(1)

/*
Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands.
The array is virtually split into a sorted and an unsorted part.
Values from the unsorted part are picked and placed at the correct position in the sorted part.
*/

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j >= 1 && v[j] < v[j - 1]; j--)
        {
            if (v[j] < v[j - 1])
            {
                swap(v[j], v[j - 1]);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    insertionSort(a);

    for (auto &i : a)
    {
        cout << i << " ";
    }
    return 0;
}
