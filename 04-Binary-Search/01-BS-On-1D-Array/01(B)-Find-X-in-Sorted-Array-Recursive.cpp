#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int binarySearch(vector<int> &arr, int low, int high, int target)
    {
        if (high < low)
            return -1;
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            return binarySearch(arr, low, mid - 1, target);
        else
            return binarySearch(arr, mid + 1, high, target);
    }
};

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    cout << "Enter the element to be searched: ";
    int x;
    cin >> x;
    Solution obj;
    int index = obj.binarySearch(a, 0, a.size() - 1, x);

    if (index == -1)
        cout << "Element not found :/";
    else
        cout << "Element found at index: " << index;

    return 0;
}