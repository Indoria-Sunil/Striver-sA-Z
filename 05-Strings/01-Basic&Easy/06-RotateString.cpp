#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.length() != goal.length())
            return false;

        string doubled = s + s;
        return doubled.find(goal) != string::npos;
    }
};

int main()
{
    Solution obj;
    cout<<obj.rotateString("abcde","cdeab");
    return 0;
}