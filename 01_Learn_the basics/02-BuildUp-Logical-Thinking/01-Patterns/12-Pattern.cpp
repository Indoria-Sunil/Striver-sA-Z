#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printingPattern(int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= i ; j++)
        {
            cout<<j+1<<" ";
        }
        for(int k = 0; k <= (num*2)-2-(2*i); k++)
        {
            cout<<"  ";
        }
        for(int j = i; j >= 0; j--)
        {
            cout<<j+1<<" ";
        }
        cout<<endl;
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