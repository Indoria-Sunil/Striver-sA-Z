#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int findingSum(int num)
{
    if (num == 0)
        return 0;
    return num + findingSum(num - 1);
}

int main()
{
    cout << "Welcome to finding Sum of N Numbers: " << endl;
    cout << "Pls Enter number: ";
    int num;
    cin >> num;
    cout << "Sum of Numbers is: " << findingSum(num);
    return 0;
}