#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void rotationByDPlaces(vector<int> &nums, int d)
{
    d = d % nums.size();
    // reverse(nums.begin(), nums.end()- d);
    // reverse(nums.end() - d, nums.end());
    // reverse(nums.begin(), nums.end());
    rotate(nums.begin(), nums.begin() + d, nums.end());
    for (auto it : nums)
    {
        cout << it << " ";
    }
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int d;
    cout << "Enter the d places for right shift: ";
    cin >> d;
    rotationByDPlaces(nums, d);

    return 0;
}