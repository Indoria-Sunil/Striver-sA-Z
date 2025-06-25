#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countingDigits(int n)
{
    for (int i = 0; i < n * 2 - 1; i++)
    {
        for (int j = 0; j < n * 2 - 1; j++)
        {
            int top = i;
            int bottom = 2 * n - 1 - i;
            int right = 2 * n - 2 - j;
            int left = j;
            int mini = min(top, min(bottom, min(left, right)));
            cout<<n - mini<<" ";
        }
        cout << endl;
    }
}

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;

    printingPattern(num);
    return 0;
}