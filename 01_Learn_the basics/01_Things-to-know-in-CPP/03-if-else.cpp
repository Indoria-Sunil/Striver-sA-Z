#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int age;
    cin >> age;

    if (age >= 18)
    {
        cout << "You can Vote!";
    }
    else
    {
        cout << "You can't Vote :/";
    }
    return 0;
}