#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printingName(string name, int num)
{
    if (num == 0)
        return;
    cout << name<<" ";
    printingName(name, num - 1);
}

int main()
{
    cout << "Welcome to Name Printer: " << endl;
    cout << "Pls Enter your Name: ";
    string name;
    cin >> name;
    cout << "Enter the number of times you want to print this name: ";
    int num;
    cin >> num;
    printingName(name, num);
    return 0;
}