#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void findingFrequency(vector<int> arr)
{
    unordered_map<int, int> map;
    int n = arr.size();
    for (int i = 0; i < n; i++)
        map[arr[i]]++;

    int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;
    // Traverse through map to find the elements.
    for (auto it : map) {
        int count = it.second;
        int element = it.first;

        if (count > maxFreq) {
            maxEle = element;
            maxFreq = count;
        }
        if (count < minFreq) {
            minEle = element;
            minFreq = count;
        }
    }

    cout << "The highest frequency element is: " << maxEle << "\n";
    cout << "The lowest frequency element is: " << minEle << "\n";
}

int main()
{
    cout << "Welcome to Max & Min frequency counter: \n";
    vector<int> v = {10, 5, 10, 15, 10, 5};
    findingFrequency(v);
    return 0;
}