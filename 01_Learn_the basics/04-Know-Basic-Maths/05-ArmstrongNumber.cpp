#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isArmstrong(int num)
{
    int digit = to_string(num).length();
    cout<<"Digits are "<< digit<<endl;
    int sum = 0;
    int temp = num;

    while (num > 0)
    {
        int rem = num % 10;
        sum = sum + round(pow(rem, digit));
        num /= 10;
    }
    return sum == temp ? true : false;   
}

int main()
{
    cout << "Welcome to Armstrong Number finder: " << endl;
    cout << "Pls Enter your number: ";
    int num;
    cin>> num;
    if (isArmstrong(num))
    {
        cout<<"The given number is Armstrong!";
    }
    else
    {
        cout<<"The given number is not Armstrong :/";
    }    
    
    return 0;
}