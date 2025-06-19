#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printingPattern(int num)
{
    for (int i = 0; i < num * 2 - 1; i++)
    {
        for (int j = 0; j < num; j++)
        {
            
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