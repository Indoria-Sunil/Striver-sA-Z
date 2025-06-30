#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int digit;
    cin>>digit;
    cout<<"Printing form 0 to "<<digit<<endl;
    int num = 0;
    while (digit)
    {
        cout<<num<<" ";
        num++;
        digit--;
    }   
    
    return 0;
}