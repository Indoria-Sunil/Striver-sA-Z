#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void printingPattern1(int num)
{

    for (int i = 0; i < num; i++)
    {
        for (int k = 0; k < num - i - 1; k++)
        {
            cout << " ";
        }

        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void printingPattern2(int num)
{

    for (int i = num; i > 0; i--)
    {
        for (int k = 0; k < num - i ; k++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i - 1; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;

    printingPattern1(num);
    printingPattern2(num);
    return 0;
}