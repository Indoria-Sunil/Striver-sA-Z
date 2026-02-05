#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &arr, int mid, int cows)
    {
        int count = 1;
        int last = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - last >= mid)
            {
                count++;
                last = arr[i];
            }
            if (count >= cows)
                return true;
        }
        return false;
    }

    int findingDistance(vector<int> &arr, int cows)
    {
        sort(arr.begin(), arr.end());
        int low = arr[0];
        int high = arr[arr.size() - 1] - arr[0];

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, mid, cows))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return high;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {0, 3, 4, 7, 10, 9};
    int k;
    cout << "Enter the number of cows: ";
    cin >> k;
    cout << "The maximum possible minimum distance between any two cows will be: "
         << obj.findingDistance(arr, k);

    return 0;
}