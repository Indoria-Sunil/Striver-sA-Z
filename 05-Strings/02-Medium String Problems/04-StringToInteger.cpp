#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int s2d(char c) { return c - '0'; }
    bool isDigit(char c)
    {
        return c >= '0' && c <= '9';
    }
    int myAtoi(string s) {
        int sign = 1;
        int num = 0;
        int i = 0;

        // --- White Spaces-----//
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        //---- Signedness----
        if (s[i] == '-') {
            // ----- -ve sign
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            // ----- +ve sign
            i++;
        }

        // -----Leading 0
        if (s[i] == '0')
            i++;

        while (i < s.length() && isDigit(s[i])) {
            int digit = s2d(s[i]);
            if (num == INT32_MAX / 10) {
                if (sign == 1) {
                    if (digit >= 7)
                        return INT32_MAX;
                } else {
                    if (digit >= 8)
                        return INT32_MIN;
                }
            }

            if (num > INT32_MAX / 10) {
                if (sign == 1) {
                    return INT32_MAX;
                } else {
                    return INT32_MIN;
                }
            }

            num = num * 10 + digit;
            i++;
        }
        return num*sign;
    }
};


int main()
{
   Solution obj;
   cout<<obj.myAtoi("1337c0d3");
    return 0;
}