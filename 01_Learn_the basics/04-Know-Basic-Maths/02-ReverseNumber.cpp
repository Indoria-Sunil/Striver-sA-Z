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

    cout<< ReverseNumber(num);
    return 0;
}