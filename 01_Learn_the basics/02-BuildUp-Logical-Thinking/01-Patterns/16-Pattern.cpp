#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printingPattern(int num)
{
    char alp = 'A';
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {            
            cout << alp << " ";
        }
        alp++;
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