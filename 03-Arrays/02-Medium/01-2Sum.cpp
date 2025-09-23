#include <bits/stdc++.h>
using namespace std;

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

// --------------- Brute Approach -----------------//
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// string twoSum(const vector<int> &arr, int count, int target)
// {
//     for (int i = 0; i < count; i++)
//     {
//         for (int j = 0; j < count; j++)
//         {
//             if (i != j && arr[i] + arr[j] == target)
//             {
//                 return to_string(i) + " " + to_string(j);
//             }

//         }

//     }
//     return "-1 -1";

// }

// --------------- Better Approach -----------------//
// Time Complexity: O(N)
// Space Complexity: O(N)
// string twoSum(const vector<int> &arr, int count, int target)
// {
//     unordered_map<int, int> hash;
//     for (int i = 0; i < count; i++)
//     {
//         int rem = target - arr[i];
//         if (hash.find(rem) != hash.end())
//         {
//             return to_string(hash[rem]) + " " + to_string(i);
//         }
//         hash[arr[i]] = i;
//     }
//     return "-1 -1";
// }

// --------------- Optimal Approach -----------------//
string twoSum(vector<int> &arr, int count, int target)
{
    vector<pair<int, int>> vec;
    for (int i = 0; i < count; i++)
    {
        vec.push_back({arr[i], i});
    }
    sort(vec.begin(), vec.end());
    int left = 0, right = count - 1;
    while (left < right)
    {
        int sum = vec[left].first + vec[right].first;
        if (sum == target)
            return to_string(vec[left].second) + " " + to_string(vec[right].second);
        else if (sum < target)
            left++;
        else
            right--;
    }

    return "-1 -1";
}

int main()
{
    fast_io;

    // Your code goes here
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    int n = arr.size();
    string result = twoSum(arr, n, target);
    cout << result << "\n";

    return 0;
}