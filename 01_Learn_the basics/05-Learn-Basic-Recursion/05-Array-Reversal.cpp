#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reversingArray(int start, int end, int arr[])
{
    if (start == end)
        return;
    swap(arr[start], arr[end]);
    reversingArray(start + 1, end - 1, arr);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Before Reversal the array is: ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << "\nNow, after Reversal the array is: ";
    reversingArray(0, sizeof(arr)/ sizeof(arr[0])-1, arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}