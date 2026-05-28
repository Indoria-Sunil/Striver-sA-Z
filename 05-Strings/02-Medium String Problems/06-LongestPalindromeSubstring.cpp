#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findAroundCenter(string s, int left, int right)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }
    string longestPalindrome(string s)
    {
        int start = 0;
        int end = 0;
        int max_Length;

        for (int i = 0; i < s.length(); i++)
        {
            int odd = findAroundCenter(s, i, i);
            int even = findAroundCenter(s, i, i + 1);
            max_Length = max(odd, even);
            if (max_Length > end - start)
            {
                start = i - (max_Length - 1) / 2;
                end = i + (max_Length / 2);
            }
        }
        return s.substr(start, end - start + 1);
    }
};

int main()
{
    Solution obj;
    cout << obj.longestPalindrome("babad")<<endl;
    cout << obj.longestPalindrome("cbbd")<<endl;

    return 0;
}