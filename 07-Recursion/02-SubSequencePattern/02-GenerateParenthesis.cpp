#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Stores all valid parentheses combinations
    vector<string> result;

class Solution
{
private:
    

    // Helper function for backtracking
    //
    // s     = current parentheses string
    // open  = number of '(' used
    // close = number of ')' used
    // n     = total number of pairs required
    void backtrack(string s, int open, int close, int n)
    {

        // If we have used 2*n characters,
        // we have created one complete valid combination.
        if (s.length() == 2 * n)
        {
            result.push_back(s);
            return;
        }

        // We can add '(' if we haven't used all n
        // opening parentheses yet.
        if (open < n)
        {
            backtrack(
                s + "(",
                open + 1,
                close,
                n);
        }

        // We can add ')' only when there is an
        // unmatched '('.
        //
        // This condition prevents invalid strings
        // such as "())(".
        if (close < open)
        {
            backtrack(
                s + ")",
                open,
                close + 1,
                n);
        }
    }

public:
    // Main function called by LeetCode
    vector<string> generateParenthesis(int n)
    {

        // Start backtracking with:
        // empty string
        // 0 opening brackets
        // 0 closing brackets
        backtrack("", 0, 0, n);

        return result;
    }
};

int main()
{
    Solution obj;
    obj.generateParenthesis(3);

    for (auto it : result)
    {
        cout << it << " \n";
    }

    return 0;
}