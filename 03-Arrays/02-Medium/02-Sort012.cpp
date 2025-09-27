#include <bits/stdc++.h>
using namespace std;

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

// --------------- Brute Force 1 Approach -----------------//
// Time Complexity: O(N log N)
// Space Complexity: O(1)
// void sortArray(const vector<int> &arr, int n)
// {
//     sort(arr.begin(), arr.end());
// }

// --------------- Brute Force 2 Approach -----------------//
// Time Complexity: O(N)
// Space Complexity: O(1)
// void sortArray(vector<int> &arr, int n)
// {
//     vector<int> count(3, 0);
//     for (int i = 0; i < n; i++)
//     {
//         count[arr[i]]++;
//     }
//     int index = 0;
//     for (int i = 0; i < 3; i++)
//     {
//         while (count[i]--)
//         {
//             arr[index++] = i;
//         }
//     }
// }

// --------------- Optimal Approach (Dutch National Flag Algorithm) -----------------//
// Time Complexity: O(N)
// Space Complexity: O(1)
void sortArray(vector<int> &arr, int n)
{
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    fast_io;

    // Your code goes here
    vector<int> arr = {0, 2, 1, 2, 0, 1, 1};
    int n = arr.size();
    sortArray(arr, n);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << "\n";

    return 0;
}