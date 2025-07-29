#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// //-----------Brute Force----------//
// int findingLargestElement(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     return nums[nums.size() -1];
// }

//-----------Optimal Approach----------//
int findingLargestElement(vector<int> &nums)
{
    int largest = INT_MIN;
    for (auto it : nums)
    {
        if (it > largest)
        {
            largest = it;
        }
    }
    return largest;
}

int main()
{
    vector<int> nums = {2, 5, 1, 3, 0};
    cout << "The largest element in the array is: " << findingLargestElement(nums);
    return 0;
}