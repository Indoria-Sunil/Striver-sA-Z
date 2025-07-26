#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &v, int start, int size)
{
    if(start <= 0) return;
    if(v[start] < v[start-1]) 
    {
        swap(v[start], v[start -1]);
        helper(v, start - 1, size);
    }
    else return;
    
}

void insertionSort(vector<int> &v, int start, int size)
{
    if (start == size)
    {
        return;
    }
    helper(v, start, size);
    insertionSort(v, start + 1, size);    
}

int main()
{
    vector<int> v = {13, 46, 24, 52, 20, 9};
    cout << "\nBefore Sorting: ";
    for (auto i : v)
        cout << i << " ";
    insertionSort(v, 1, v.size());
    cout << "\nAfter Sorting: ";
    for (auto i : v)
        cout << i << " ";
    return 0;
}