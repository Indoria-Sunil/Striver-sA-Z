#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printingPattern(int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {

            if (i == 0 || i == num - 1 || j == 0 || j == num - 1)
            {
                cout << "*";
            }
            else
                cout << " ";
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