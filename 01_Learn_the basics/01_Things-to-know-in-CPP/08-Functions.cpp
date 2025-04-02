#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int AddingNumbers(int first,int second)
{
    return first + second;
}



int main()
{
    int first, second;
    cout<<"Enter first number: ";
    cin>>first;
    cout<<"Enter second number: ";
    cin>>second;

    cout<<AddingNumbers(first, second);
    
    return 0;
}