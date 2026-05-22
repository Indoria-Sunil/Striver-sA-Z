#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        stack<char> st;
        int count = 0;
        int ans = 0;
        for (auto it : s)
        {
            if (it == '(')
            {
                count++;
                ans = max(ans, count);
            }
            else if (it == ')')
                count--;
            else
                continue;
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    cout << obj.maxDepth("(1+(2*3)+((8)/4))+1");
    return 0;
}