// Time Complexity: O(N log(N))
// Auxiliary Space: O(n)

/*
- The Merge Sort algorithm is a sorting algorithm that is based on the Divide and Conquer paradigm.
- In this algorithm, the array is initially divided into two equal halves and then they are combined in a sorted manner.
- It is stable sort algorithm and does not happen in-place and requires extra array to store the elements.

--> Merge Sort Working Process:

- Think of it as a recursive algorithm continuously splits the array in half until it cannot be further divided.
- This means that if the array becomes empty or has only one element left, the dividing will stop, i.e. it is the base case to stop the recursion.
- If the array has multiple elements, split the array into halves and recursively invoke the merge sort on each of the halves.
- Finally, when both halves are sorted, the merge operation is applied. Merge operation is the process of taking two smaller sorted arrays and combining them to eventually make a larger one.
*/

#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector<int> &v, const int &low, const int &high)
{
    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;
    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);

    vector<int> temp = v;

    int index1 = mid, index2 = high, size = high;

    while (index2 >= mid + 1 && index1 >= low)
    {
        temp[size--] = (v[index2] > v[index1]) ? v[index2--] : v[index1--];
    }

    while (index1 >= low)
    {
        temp[size--] = v[index1--];
    }
    while (index2 >= mid + 1)
    {
        temp[size--] = v[index2--];
    }
    v = temp;
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

    mergeSort(v, 0, n - 1);

    for (auto &i : v)
        cout << i << " ";
    return 0;
}
