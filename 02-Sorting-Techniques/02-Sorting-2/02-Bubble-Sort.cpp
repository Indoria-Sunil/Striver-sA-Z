#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bubblePass(vector<int> &v, int n, int i)
{
    if (i == n - 1)
        return;
    if (v[i] > v[i + 1])
        swap(v[i], v[i + 1]);
    bubblePass(v, n, i + 1);
}

void bubbleSort(vector<int> &v, int n)
{
    if (n == 1)
        return;
    bubblePass(v, n, 0);
    bubbleSort(v, n - 1);
}

int main()
{
    vector<int> v = {13, 46, 24, 52, 20, 9};
    cout << "\nBefore Sorting: ";
    for (auto i : v)
        cout << i << " ";
    bubbleSort(v, v.size() );
    cout << "\nAfter Sorting: ";
    for (auto i : v)
        cout << i << " ";
    return 0;
}