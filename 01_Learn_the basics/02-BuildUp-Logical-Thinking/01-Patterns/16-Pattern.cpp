#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printingPattern(int num)
{
    for (int i = 0; i < num; i++)
    {
        char alp = 'A';
        for (int j = 0; j < num - i; j++)
        {            
            cout << alp++ << " ";
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