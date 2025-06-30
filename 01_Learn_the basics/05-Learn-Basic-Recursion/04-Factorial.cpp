#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findingFactorial(int num)
{
    if (num == 1)
        return 1;
    return num * findingFactorial(num - 1);
}

int main()
{
    cout << "Welcome to factorial finding: " << endl;
    cout << "Pls Enter number: ";
    int num;
    cin >> num;
    cout << findingFactorial(num);
    return 0;
}