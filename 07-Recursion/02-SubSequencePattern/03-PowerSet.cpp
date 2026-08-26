#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    /*
        ---------------------------------------------------------
        APPROACH 1: RECURSION + BIT MANIPULATION
        ---------------------------------------------------------

        Each character is represented by one bit in the mask.

        For example, for s = "abc":

        Bit 2   Bit 1   Bit 0
          c       b       a

        mask = 101 means:
        - Bit 0 = 1 -> Take 'a'
        - Bit 1 = 0 -> Don't take 'b'
        - Bit 2 = 1 -> Take 'c'

        Therefore, mask 101 represents "ac".

        At every index, recursion has two choices:

        1. Don't choose the current character
           -> Keep the mask unchanged

        2. Choose the current character
           -> Set the corresponding bit to 1
    */
    void solveBitManipulation(int index, int size, int mask, const string &s, vector<string> &ans)
    {
        /*
            Base Case:

            If index reaches size, it means we have made a
            Take/Don't Take decision for every character.

            The final mask now represents one subsequence.
        */
        if (index == size)
        {
            string temp = "";

            /*
                Check every bit of the mask.

                If the i-th bit is set (1), include s[i]
                in the current subsequence.
            */
            for (int i = 0; i < size; i++)
            {
                /*
                    (1 << i) creates a number where only
                    the i-th bit is set.

                    mask & (1 << i) checks whether the
                    i-th bit of mask is set.
                */
                if (mask & (1 << i))
                {
                    // Include the corresponding character.
                    temp += s[i];
                }
            }

            // Store the generated subsequence.
            ans.push_back(temp);
            return;
        }

        /*
            CHOICE 1: DON'T TAKE s[index]

            The mask remains unchanged because we are not
            selecting the current character.
        */
        solveBitManipulation(
            index + 1,
            size,
            mask,
            s,
            ans);

        /*
            CHOICE 2: TAKE s[index]

            (1 << index) creates a bitmask with the current
            index-th bit set to 1.

            Bitwise OR (|) sets that bit while preserving all
            previously selected characters.

            Example:

            mask       = 001
            1 << index = 010
            -----------------
            OR result  = 011
        */
        solveBitManipulation(
            index + 1,
            size,
            mask | (1 << index),
            s,
            ans);
    }

    /*
        ---------------------------------------------------------
        APPROACH 2: SIMPLE RECURSION (TAKE / DON'T TAKE)
        ---------------------------------------------------------

        At every character, we have two choices:

        1. Take the character
        2. Don't take the character
    */
    void solveSimple(
        int index,
        const string &s,
        string current,
        vector<string> &ans)
    {
        /*
            Base Case:

            If all characters have been processed, the current
            string is one valid subsequence.
        */
        if (index == s.size())
        {
            ans.push_back(current);
            return;
        }

        /*
            CHOICE 1: TAKE the current character.

            Add s[index] to the current subsequence and
            move to the next character.
        */
        solveSimple(
            index + 1,
            s,
            current + s[index],
            ans);

        /*
            CHOICE 2: DON'T TAKE the current character.

            Keep the current subsequence unchanged and
            move to the next character.
        */
        solveSimple(
            index + 1,
            s,
            current,
            ans);
    }

public:
    /*
        ---------------------------------------------------------
        Generate Power Set Using Simple Recursion
        ---------------------------------------------------------
    */
    vector<string> powerSetUsingSimpleRecursion(string s)
    {
        vector<string> ans;

        /*
            Start from index 0.

            Initially, the current subsequence is empty.
        */
        solveSimple(0, s, "", ans);

        return ans;
    }

    /*
        ---------------------------------------------------------
        Generate Power Set Using Recursion + Bit Manipulation
        ---------------------------------------------------------
    */
    vector<string> powerSetUsingBitManipulationRecursion(string s)
    {
        vector<string> ans;

        /*
            Start from:

            index = 0
            mask  = 0

            For "abc":

            Initial mask = 000

            Recursion will generate all possible masks:

            000 -> ""
            001 -> "a"
            010 -> "b"
            011 -> "ab"
            100 -> "c"
            101 -> "ac"
            110 -> "bc"
            111 -> "abc"
        */
        solveBitManipulation(0, s.length(), 0, s, ans);

        return ans;
    }
};

int main()
{
    string s = "abc";

    Solution obj;

    /*
        Generate all subsequences using
        recursion + bit manipulation.
    */
    vector<string> result =
        obj.powerSetUsingBitManipulationRecursion(s);

    // Print all generated subsequences.
    cout << "All subsequences:" << endl;

    for (const string &subsequence : result)
    {
        cout << "\"" << subsequence << "\"" << endl;
    }

    return 0;
}