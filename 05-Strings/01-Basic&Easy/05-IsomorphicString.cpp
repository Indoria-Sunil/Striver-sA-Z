#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mapSt;
        unordered_map<char, char> mapTs;

        for (int i = 0; i < s.length(); i++)
        {
            char sc = s[i], tc = t[i];
            if (mapSt.count(sc) && mapSt[sc] != tc)
                return false;
            if (mapTs.count(tc) && mapTs[tc] != sc)
                return false;
            mapSt[sc] = tc;
            mapTs[tc] = sc;
        }
        return true;
    }
};

int main()
{
    Solution obj;
    cout<<obj.isIsomorphic("egg", "add");
    return 0;
}