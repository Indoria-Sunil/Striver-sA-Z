#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printingPattern(int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout << j + 1<<" ";
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