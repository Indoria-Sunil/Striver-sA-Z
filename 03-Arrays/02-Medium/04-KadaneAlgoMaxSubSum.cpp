#include <bits/stdc++.h>
using namespace std;

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

// --------------- Brute Force Approach -----------------//
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// int maxSubarraySum(const vector<int> &arr, int n)
// {
//     int maxi = INT_MIN; // maximum sum

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             // subarray = arr[i.....j]
//             int sum = 0;

//             // add all the elements of subarray:
//             for (int k = i; k <= j; k++)
//             {
//                 sum += arr[k];
//             }

//             maxi = max(maxi, sum);
//         }
//     }

//     return maxi;
// }

// --------------- Better Approach -----------------//
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// int maxSubarraySum(const vector<int> &arr, int n)
// {
//     int maxSum = INT_MIN; // maximum sum

//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             sum += arr[j];
//             maxSum = max(maxSum, sum); // getting the maximum
//         }
//     }

//     return maxSum;
// }

// --------------- Optimal Approach (Kadane's Algorithm) -----------------//
// Time Complexity: O(N)
// Space Complexity: O(1)
int maxSubarraySum(const vector<int> &arr, int n)
{
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }

    return maxSum;
}

int main()
{
    fast_io;

    // Your code goes here
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = arr.size();
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}