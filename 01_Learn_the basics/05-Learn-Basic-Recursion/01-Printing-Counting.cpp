#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// // --------- Ascending Order -----------//
// void printingCounting(int num)
// {
//     if (num < 0)
//     {
//         return;
//     }
//     printingCounting(num - 1);
//     cout << num << " ";
// }

// --------- Descending Order -----------//
void printingCounting(int num)
{
    if (num < 0)
    {
        return;
    }
    cout << num << " ";
    printingCounting(num - 1);
}

int main()
{
    cout << "Welcome to Counting Printer: " << endl;
    cout << "Pls Enter your number: ";
    int num;
    cin >> num;
    printingCounting(num);
    return 0;
}