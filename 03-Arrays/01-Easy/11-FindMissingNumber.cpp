#include <bits/stdc++.h>
using namespace std;

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

//--------------- Brute Force Approach -----------------//
// Time Complexity: O(N^2)
// int missingNumber(const vector<int> &a, int N)
// {

//     for (int i = 1; i <= N; i++)
//     {
//         bool flag = false;
//         for (int j = 0; j < N - 1; j++)
//         {
//             if (a[j] == i)
//             {
//                 flag = true;
//                 break;
//             }
//         }
//         if (!flag)
//         {
//             return i;
//         }
//     }

//     return -1;
// }

//--------------- Optimal Approach -----------------//
// Time Complexity: O(N)
// int missingNumber(const vector<int> &a, int N)
// {

//     int hash[N + 1] = {0};
//     for (int i = 0; i < N - 1; i++)
//     {
//         hash[a[i]]++;
//     }

//     for (int i = 1; i <= N; i++)
//     {
//         if (hash[i] == 0)
//         {
//             return i;
//         }
//     }

//     return -1;
// }

// -------------- Optimal Approach (Using Sum Formula) -----------------//
// Time Complexity: O(N)
// int missingNumber(const vector<int> &a, int N)
// {

//     int total = (N * (N + 1)) / 2;
//     int sum = 0;
//     for (auto it : a)
//     {
//         sum += it;
//     }
//     int missingNum = total - sum;
//     return missingNum;
// }

// -------------- Optimal Approach (Using XOR) -----------------//
// Time Complexity: O(N)
int missingNumber(const vector<int> &a, int N)
{
    int xor1 = 0;
    int xor2 = 0;

    for (int i = 0; i < N - 1; i++)
    {
        xor2 = xor2 ^ a[i];
        xor1 = xor1 ^ (i + 1);
    }

    int missingNum = xor1 ^ xor2;
    return missingNum;
}

int main()
{
    fast_io;

    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << ans << "\n";

    return 0;
}