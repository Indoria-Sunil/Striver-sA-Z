#include <bits/stdc++.h>
using namespace std;

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

// --------------- Optimal Approach (Kadane's Algorithm) -----------------//
// Time Complexity: O(N)
// Space Complexity: O(1)
void maxSubarraySum(const vector<int> &arr, int n)
{
    int maxSum = INT_MIN;
    int currSum = 0;
    int start = 0, end = 0, tempStart = 0;
    for (int i = 0; i < n; i++)
    {
        if (currSum == 0)
        {
            tempStart = i;
        }
        currSum += arr[i];
        if (currSum > maxSum)
        {
            maxSum = currSum;
            start = tempStart;
            end = i;
        }
        if (currSum < 0)
        {
            currSum = 0;
        }
    }

    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }

    return;
}

int main()
{
    fast_io;

    // Your code goes here
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = arr.size();
    maxSubarraySum(arr, n);

    return 0;
}