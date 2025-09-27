#include <bits/stdc++.h>
using namespace std;

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

// -------------- Brute Force Approach -----------------//
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// int majorityElement(const vector<int> &arr, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         int count = 0;
//         for (int j = 0; j < n; j++)
//         {
//             if (arr[i] == arr[j])
//                 count++;
//         }

//         if (count > n / 2)
//             return arr[i];
//     }
//     return -1;
// }

// -------------- Better Approach -----------------//
// Time Complexity: O(N)
// Space Complexity: O(N)
// int majorityElement(const vector<int> &arr, int n)
// {
//     unordered_map<int, int> freq;
//     for (auto it : arr)
//     {
//         freq[it]++;
//         if (freq[it] > n / 2)
//             return it;
//     }
//     return -1;
// }

// -------------- Optimal Approach (Boyer-Moore Voting Algorithm) -----------------//
// Time Complexity: O(N)
// Space Complexity: O(1)
int majorityElement(const vector<int> &arr, int n)
{
    int count = 0;
    int ele;
    for (int i = 0; i < n; i++)
    {

        if (count == 0)
        {
            ele = arr[i];
            count++;
        }
        else if (arr[i] == ele)
            count++;
        else
            count--;
    }

    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
            count1++;
    }

    if (count1 > n / 2)
    {
        return ele;
    }

    return -1;
}

int main()
{
    fast_io;

    // Your code goes here
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2};
    int n = arr.size();
    int ans = majorityElement(arr, n);
    cout << ans << "\n";

    return 0;
}