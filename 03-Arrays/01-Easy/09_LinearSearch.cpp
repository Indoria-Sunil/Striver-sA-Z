#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void searching(vector<int> nums, int num)
{
    for (auto it : nums)
    {
        if (it == num)
        {
            cout << "Number found";
            return;
        }
    }
    cout << "Number not found!";
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int num;
    cout << "Enter the number you want to search: ";
    cin >> num;
    searching(nums, num);

    return 0;
}