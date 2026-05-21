#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        string ans;
        unordered_map<char, int> mp;

        for (auto it : s)
        {
            mp[it]++;
        }
        vector<pair<char, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), [](pair<char, int> &a, pair<char, int> &b)
             { return a.second > b.second; });

        for (auto p : vec)
        {
            ans += string(p.second, p.first);
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    cout << obj.frequencySort("tree");
    return 0;
}