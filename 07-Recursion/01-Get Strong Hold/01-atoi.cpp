#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int convert(string s, int index, long long ans, int sign)
    {

        // Base case: end of string or non-digit
        if (index == s.size() || !isdigit(s[index]))
        {
            return sign * ans;
        }

        // Add current digit
        ans = ans * 10 + (s[index] - '0');

        // Overflow check
        if (sign * ans > INT_MAX)
            return INT_MAX;
        if (sign * ans < INT_MIN)
            return INT_MIN;

        // Recursive call
        return convert(s, index + 1, ans, sign);
    }

    int myAtoi(string s)
    {

        int i = 0;

        // 1. Skip spaces
        while (i < s.size() && s[i] == ' ')
        {
            i++;
        }

        // 2. Determine sign
        int sign = 1;

        if (i < s.size() && s[i] == '+' || s[i] == '-')
        {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        // 3. Recursively process digits
        return convert(s, i, 0, sign);
    }
};

int main()
{
    Solution obj;
    cout << obj.myAtoi("     -2356463");

    return 0;
}