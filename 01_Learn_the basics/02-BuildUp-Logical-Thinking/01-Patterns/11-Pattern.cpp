#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printingPattern(int num)
{
    bool ch = 1;

    for (int i = 0; i < num; i++)
    {

        for (int j = 0; j <= i; j++)
        {
            cout <<ch<<" ";
            ch = !ch;
        }
        cout << endl;
    }
}

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;

    printingPattern(num);
    return 0;
}