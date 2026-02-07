#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPartitions(vector<int> arr, int maxSum)
    {
        int n = arr.size();
        int partitions = 1;
        long long subarraySum = 0;

        for (int i = 0; i < n; i++)
        {
            if (subarraySum + arr[i] <= maxSum)
            {
                // add pages to current student
                subarraySum += arr[i];
            }
            else
            {
                // add pages to next student
                partitions++;
                subarraySum = arr[i];
            }
        }
        return partitions;
    }

    // Finds the minimum largest subarray sum possible for at most k partitions
    int splitArray(vector<int> &arr, int k)
    {
        int low = *max_element(arr.begin(), arr.end());   // largest element
        int high = accumulate(arr.begin(), arr.end(), 0); // sum of all elements

        // Binary search for the smallest maxSum
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int partitions = countPartitions(arr, mid);

            if (partitions > k)
            {
                low = mid + 1; // too many partitions → increase maxSum
            }
            else
            {
                high = mid - 1; // valid but try smaller maxSum
            }
        }
        return low;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {7, 2, 5, 10, 8};
    int size = arr.size();
    int k;
    cout << "Enter the number of partitions: ";
    cin >> k;
    int ans = obj.splitArray(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}