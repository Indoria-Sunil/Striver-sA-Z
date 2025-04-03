#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printingPatter(int num)
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

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;

    printingPatter(num);
    return 0;
}