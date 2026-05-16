#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &str)
    {
        sort(str.begin(), str.end());
        string ans = "";
        string first = str[0], last = str[str.size() - 1];

        for (int i = 0; i < min(first.size(), last.size()); i++)
        {
            if (first[i] != last[i])
                return ans;
            ans += first[i];
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<string> str = {"flower", "flow", "flight"};
    cout << obj.longestCommonPrefix(str);
    return 0;
}