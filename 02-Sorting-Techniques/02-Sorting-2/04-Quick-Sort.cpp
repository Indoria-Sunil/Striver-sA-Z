#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int low, int high)
{
    int pivot = v[low];
    int i = low + 1;
    int j = high;
    while (i <= j)
    {
        while (i <= high && v[i] <= pivot)
        {
            i++;
        }
        while (v[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(v[i], v[j]);
        }
    }
    swap(v[low], v[j]);
    return j;
}

void quickSort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(v, low, high);
        quickSort(v, low, pivotIndex - 1);
        quickSort(v, pivotIndex + 1, high);
    }
}

int main()
{
    vector<int> v = {13, 46, 24, 52, 20, 9};
    cout << "\nBefore Sorting: ";
    for (auto i : v)
        cout << i << " ";
    quickSort(v, 0, v.size() - 1);
    cout << "\nAfter Sorting: ";
    for (auto i : v)
        cout << i << " ";
    return 0;
}