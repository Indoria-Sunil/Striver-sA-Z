#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:

    void solve(int n, string &s, vector<string> &ans)
    {
        // Base case:
        // If the string has reached length n,
        // store it in the answer.
        if (s.size() == n)
        {
            ans.push_back(s);
            return;
        }

        // Choice 1: Add '0'
        // We can always add 0.
        s.push_back('0');

        // Explore this choice.
        solve(n, s, ans);

        // Backtrack:
        // Remove 0 and return to the previous state.
        s.pop_back();


        // Choice 2: Add '1'
        // We can add 1 only if:
        // - the string is empty, OR
        // - the previous character is 0
        //
        // This prevents "11".
        if (s.empty() || s.back() == '0')
        {
            // Add 1.
            s.push_back('1');

            // Explore this choice.
            solve(n, s, ans);

            // Backtrack:
            // Remove 1 and return to the previous state.
            s.pop_back();
        }
    }

public:

    vector<string> generateBinaryStrings(int n)
    {
        vector<string> ans;
        string s;

        // Start the backtracking process.
        solve(n, s, ans);

        return ans;
    }
};


int main()
{
    Solution obj;

    vector<string> ans = obj.generateBinaryStrings(3);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}