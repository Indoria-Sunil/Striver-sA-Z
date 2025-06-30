#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int start, int end, string str)
{
    if (start >= end)
        return true;
    if (str[start] != str[end])
        return false;
    return isPalindrome(start + 1, end - 1, str);
}

int main()
{
    cout << "Welcome to finding Palindrome String: " << endl;
    cout << "Pls Enter String: ";
    string str;
    cin >> str;
    if (isPalindrome(0, str.length() - 1, str))
    {
        cout << "Is Palindrome";
    }
    else
        cout << "Not, Palindrome!";

    return 0;
}