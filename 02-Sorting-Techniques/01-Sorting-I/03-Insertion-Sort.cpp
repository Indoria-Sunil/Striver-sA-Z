#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void insertionSorting(vector<int> &v)
{
    int count = v.size();
    for (int i = 1; i < count; i++)
    {
        int j = i;
        for (; j > 0; j--)
        {
            if (v[j] < v[j - 1])
            {
                swap(v[j], v[j-1]);      
            }            
        }
          
    }   
}

int main()
{
    vector<int> v = {13,46,24,52,20,9};
    cout<<"\nBefore Sorting: ";
    for(auto i : v) cout<<i<<" ";
    insertionSorting(v);
    cout<<"\nAfter Sorting: ";
    for(auto i : v) cout<<i<<" ";
    return 0;
}