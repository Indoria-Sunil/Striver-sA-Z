#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeOuterParenthesesBrute(string s)
    {
        string ans = "";
        stack<char> st;
        for (auto it : s)
        {
            if (it == '(')
            {
                if (!st.empty())
                {
                    ans.push_back('(');
                }
                st.push('(');
            }
            else if (it == ')')
            {
                st.pop();
                if (!st.empty())
                    ans.push_back(')');
            }
        }
        return ans;
    }
    string removeOuterParenthesesBetter(string s)
    {
        string ans = "";
        int counter = 0;
        for (auto it : s)
        {
            if (it == '(')
            {
                if (counter > 0)
                {
                    ans.push_back('(');
                }
                counter++;
            }
            else if (it == ')')
            {
                counter--;
                if (counter > 0)
                    ans.push_back(')');
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    string s = "(()())(())";
    // string ans = obj.removeOuterParenthesesBrute(s);
    string ans = obj.removeOuterParenthesesBetter(s);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}
