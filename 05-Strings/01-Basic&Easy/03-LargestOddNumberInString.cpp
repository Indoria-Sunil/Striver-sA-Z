#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2)
                return num.substr(0, i + 1);
        }
        return "";
    }
};


int main()
{

    Solution obj;
    string ans = obj.largestOddNumber("42067");
    cout<< ans;
    return 0;
}