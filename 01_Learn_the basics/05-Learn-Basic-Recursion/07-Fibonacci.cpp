#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Fibonacci(int num)
{
    if(num < 0) return 0;
    if (num <= 1) return num;
    int curr = Fibonacci(num - 1) + Fibonacci(num - 2);  
    return curr;
}


int main()
{
    cout << "Welcome to finding Fibonacci Series: " << endl;
    cout << "Pls Enter number: ";
    int num;
    cin >> num;
    cout<<Fibonacci(num);
    return 0;
}