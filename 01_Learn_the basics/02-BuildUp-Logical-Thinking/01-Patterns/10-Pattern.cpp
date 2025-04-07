#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void printingPatter1(int num)
{

    for (int i = 1; i <= num*2-1; i++)
    {
        int stars = i;
        if(i > num) stars = 2*num - i;

        for(int j = 1; j <= stars; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}



int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;

    printingPatter1(num);
    return 0;
}