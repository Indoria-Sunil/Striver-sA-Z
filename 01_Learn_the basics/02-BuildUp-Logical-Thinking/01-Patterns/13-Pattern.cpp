#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printingPatter(int num)
{
    int dig = 1;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << dig << " ";
            dig++;
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