#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int binarySearch(vector<int> &arr, int target)
    {
        int low = 0, high = arr.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target)
                return mid;
            else if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    cout << "Enter the element to be searched: ";
    int x;
    cin >> x;
    Solution obj;
    int index = obj.binarySearch(a, x);

    if (index == -1)
        cout << "Element not found :/";
    else
        cout << "Element found at index: " << index << endl;

    return 0;
}