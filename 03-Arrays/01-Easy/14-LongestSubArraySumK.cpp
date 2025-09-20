#include <bits/stdc++.h>
using namespace std;

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

// --------------- Brute Force 1 Approach -----------------//
// Time Complexity: O(N^3)
// Space Complexity: O(1)
// int getLongestSubArray(const vector<int> &arr, long long k)
// {
//     int n = arr.size();
//     int maxLength = 0;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             long long sum = 0;
//             for (int k = i; k <= j; k++)
//             {
//                 sum += arr[k];
//             }
//             if (sum == k)
//             {
//                 maxLength = max(maxLength, j - i + 1);
//             }
//         }
//     }
//     return maxLength;
// }

// --------------- Brute Force 2 Approach -----------------//
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// int getLongestSubArray(const vector<int> &arr, long long k)
// {
//     int n = arr.size();
//     int maxLength = 0;

//     for (int i = 0; i < n; i++)
//     {
//         long long sum = 0;
//         for(int j = i; j < n; j++)
//         {
//             sum += arr[j];
//             if (sum == k)
//             {
//                 maxLength = max(maxLength, j - i + 1);
//             }
//         }
//     }

//     return maxLength;
// }

// -------------- Better Approach -----------------//
// Time Complexity: O(N log N)
// Space Complexity: O(N)
// int getLongestSubArray(const vector<int> &arr, long long k)
// {
//     int n = arr.size();
//     int maxLength = 0;
//     unordered_map<long long, int> prefixSumIndex;
//     long long prefixSum = 0;

//     for (int i = 0; i < n; i++)
//     {
//         prefixSum += arr[i];
//         if (prefixSum == k)
//         {
//             maxLength = i + 1;
//         }
//         long long rem = prefixSum - k;
//         if (prefixSumIndex.find(rem) != prefixSumIndex.end())
//         {
//             maxLength = max(maxLength, prefixSumIndex[rem] - i);
//         }

//         if (prefixSumIndex.find(prefixSum) == prefixSumIndex.end())
//         {
//             prefixSumIndex[prefixSum] = i;
//         }
//     }

//     return maxLength;
// }

// -------------- Optimal Approach if array contains 0 and +ve -----------------//
// Time Complexity: O(N)
int getLongestSubArray(const vector<int> &arr, long long k)
{
    int n = arr.size();
    int maxLength = 0;
    int right = 0, left = 0;
    long long sum = arr[0];

    while (right < n)
    {
        while (sum > k && left <= right)
        {
            sum -= arr[left];
            left++;
        }

        if (sum == k)
        {
            maxLength = max(maxLength, right - left + 1);
        }

        right++;
        if (right < n)
            sum += arr[right];
    }

    return maxLength;
}

int main()
{
    fast_io;

    // Your code goes here
    vector<int> a = {2, 3, 5, 1, 9};
    long long sum = 10;
    int len = getLongestSubArray(a, sum);
    cout << len << "\n";
    return 0;
}