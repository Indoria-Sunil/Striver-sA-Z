#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void leftRotating(vector<int> &nums)
{
    int temp = nums[0];
    int i;
    for (i = 0; i < nums.size()-1; i++)
    {
        nums[i] = nums[i+1];
    }
    nums[i] = temp;    
}

int main()
{
    vector<int> nums = {1,2,3,4,5};
    cout<<"Before Left Rotating Array was: ";
    for(auto it : nums) cout<<it<<" ";
    leftRotating(nums);
    cout<<"\nAfter Rotating Array is: ";
    for(auto it : nums) cout<<it<<" ";
    return 0;
}