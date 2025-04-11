#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printingPattern(int num)
{
    int spaces = 2 * num - 2;
    for (int i = 0; i < 2 * num - 1; i++)
    {
        int stars = i;
        if (i >= num)
            stars = 2 * num - i - 2;
        for (int j = 0; j <= stars; j++)
        {
            cout << "*";
        }
        for (int k = 0; k < spaces; k++)
        {
            cout << " ";
        }
        for (int j = 0; j <= stars; j++)
        {
            cout << "*";
        }
        if (i < num-1)
            spaces -= 2;
        else
            spaces += 2;
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