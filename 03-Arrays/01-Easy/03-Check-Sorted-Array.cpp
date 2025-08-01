#include <iostream>
#include <bits/stdc++.h>
using namespace std;




bool isSorted(vector<int> nums)
{
    if (nums.size() == 0 || nums.size() == 1)
        return true;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < nums[i - 1])
            return false;
    }

    return true;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 0};
    if (isSorted(nums))
        cout << "Array is sorted";
    else
        cout << "Array is not sorted";

    return 0;
}