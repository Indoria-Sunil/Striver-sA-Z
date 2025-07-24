#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}


void mergeSort(vector<int> &v, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);
    merge(v, low, mid, high);
}

int main()
{
    vector<int> v = {38, 27, 43, 3, 9, 82, 10};
    cout << "\nBefore Sorting: ";
    for (auto i : v)
        cout << i << " ";
    mergeSort(v, 0, v.size() - 1);
    cout << "\nAfter Sorting: ";
    for (auto i : v)
        cout << i << " ";
    return 0;
}