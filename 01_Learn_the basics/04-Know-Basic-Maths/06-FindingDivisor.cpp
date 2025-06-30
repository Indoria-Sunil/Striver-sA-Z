#include <iostream>
#include <bits/stdc++.h>
using namespace std;



//--------------Brute Force---------------//
void findingDivisor(int num)
{
    vector<int> v;
    int i = 1;
    while (i <= num)
    {
        if (num % i == 0)
        {
            v.push_back(i);
        }
        i++;
    }
    sort(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i << " ";
    }
}



//--------------Optimal---------------//
// void findingDivisor(int num)
// {
//     vector<int> v;
//     int i = 1;
//     while (i <= sqrt(num))
//     {
//         if (num % i == 0)
//         {
//             v.push_back(i);
//             if (num / i != i)
//             {
//                 v.push_back(num / i);
//             }
//         }
//         i++;
//     }
//     sort(v.begin(), v.end());
//     for (auto i : v)
//     {
//         cout << i << " ";
//     }
// }

int main()
{

    cout << "Welcome to Finding Divisor: " << endl;
    cout << "Pls Enter your number: ";
    int num;
    cin >> num;
    findingDivisor(num);
    return 0;
}