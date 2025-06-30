#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// // ---------Brute Force----------//
// int findingGCD(int first, int second)
// {
//     int ans;
//     for (int i = 1; i <= min(first, second); i++)
//     {
//         if (first % i == 0 && second % i == 0)
//         {
//             ans = i;
//         }
//     }
//     return ans;
// }


// // ---------Better Approach----------//
// int findingGCD(int first, int second)
// {
//     int ans;
//     for (int i = min(first, second); i >= 1; i--)
//     {
//         if (first % i == 0 && second % i == 0)
//         {
//             ans = i;
//             break;
//         }
//     }
//     return ans;
// }


// ---------Optimal Approach----------//
int findingGCD(int first, int second)
{
    while (first > 0 && second > 0)
    {
        if (first > second)
        {
            first %= second;
        }
        else second %= first;        
    }
    if (first == 0)
    {
        return second;
    }
    return first;    
}

int main()
{
    cout << "Welcome to GCD finder: " << endl;
    cout << "Pls Enter your numbers: ";
    int first, second;
    cin >> first >> second;
    cout << "GCD for the above numbers is: " << findingGCD(first, second);
    return 0;
}