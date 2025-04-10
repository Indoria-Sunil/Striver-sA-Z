#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printingPattern(int num)
{

    for (int i = 0; i < num; i++)
    {
        char alp = 'A';
        for (int k = 0; k < num - i - 1; k++)
        {
            cout << " ";
        }
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j <= 2 * i + 1; j++)
        {
            cout << alp;
            if (j <= breakpoint) alp++;
            else alp--;            
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