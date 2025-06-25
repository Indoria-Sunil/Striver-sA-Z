#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// // Brute Force 
// int countingDigits(int num)
// {
//     if (num <= 0) return -1;    
//     int count = 0;
//     while (num > 0)
//     {
//         count++;
//         num /= 10;
//     }
//     return count;
// }


// Optimized 
int countingDigits(int num)
{
    return int (log10(num) + 1);
}

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;

    cout<< countingDigits(num);
    return 0;
}