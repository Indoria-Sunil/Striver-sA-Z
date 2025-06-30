#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ReverseNumber(int num)
{
    int ans = 0;
    while (num)
    {
        int rem = num % 10;
        ans = ans * 10 + rem;
        num /= 10;
    }
    return ans;
}

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;

    if (ReverseNumber(num) == num) {
        cout << "Yes! It's a Palindrome" << endl;
    } else {
        cout << "Not a Palindrome :/" << endl;
    }
    return 0;
}