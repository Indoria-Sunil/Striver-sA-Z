#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
class Solution
{
private:
    long long powBrute(long long base, long long exp)
    {
        long long result = 1;
        while (exp > 0)
        {
            if (exp & 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    long long powRecursive(long long base, long long exp)
    {
        if (exp == 0)
            return 1;
        long long half = powRecursive(base, exp / 2);
        long long result = (half * half) % MOD;
        if (exp % 2 == 1)
            result = (result * base) % MOD;
        return result;
    }

public:
    int countGoodNumbers(long long n)
    {
        long long even = (n + 1) / 2;              // Count of even positions
        long long odd = n / 2;                     // Count of odd positions
        return (powRecursive(5, even) * powRecursive(4, odd)) % MOD; // Calculate the number of good numbers
        // return (powBrute(5, even) * powBrute(4, odd)) % MOD; // Calculate the number of good numbers
    }
};

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    Solution sol;
    int result = sol.countGoodNumbers(n);
    cout << "Number of good numbers: " << result << endl;

    return 0;
}