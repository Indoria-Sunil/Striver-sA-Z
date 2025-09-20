#include <bits/stdc++.h>
using namespace std;


// --------------- Brute Force Approach -----------------//
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// int getSingleElement(const vector<int> &arr) {
//     int n = arr.size();
//     for (int  i = 0; i < n; i++)
//     {
//         bool flag = false;
//         for (int j = 0; j < n; j++)
//         {
//             if (i != j && arr[i] == arr[j])
//             {
//                 flag = true;
//                 break;
//             }

//         }
//         if (!flag)
//             return arr[i];
//     }
//     return -1;

// }

// --------------- Better Approach -----------------//
// Time Complexity: O(N + M)
// Space Complexity: O(M)
// int getSingleElement(const vector<int> &arr)
// {
//     int n = arr.size();
//     int maxi = *max_element(arr.begin(), arr.end());
//     vector<int> hash(maxi + 1, 0);
//     for (int i = 0; i < n; i++)
//     {
//         hash[arr[i]]++;
//     }
//     for (auto it : hash)
//     {
//         if (it == 1)
//             return it;
//     }
//     return -1;
// }



// --------------- Better Approach -----------------//
// Time Complexity: O(N)
// Space Complexity: O(N)
// int getSingleElement(const vector<int> &arr)
// {
//     int n = arr.size();
//     unordered_map<int, int> freq;
//     for (auto it : arr)
//     {
//         freq[it]++;
//     }

//     for (auto it : freq)
//     {
//         if (it.second == 1)
//         {
//             return it.first;
//         }
//     }
//     return -1;
// }

// -------------- Optimal Approach (Using XOR) -----------------//
// Time Complexity: O(N)
// Space Complexity: O(1)
int getSingleElement(const vector<int> &arr) {
    int result = 0;
    for (int num : arr) {
        result ^= num;
    }
    return result;
}

int main()
{

    // Your code goes here
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << ans << "\n";

    return 0;
}