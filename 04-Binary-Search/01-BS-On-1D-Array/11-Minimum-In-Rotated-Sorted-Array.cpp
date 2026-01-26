#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int ans = INT_MAX;
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[low] <= nums[mid])
            {
                ans = min(nums[low], ans);
                low = mid + 1;
            }
            else
            {
                ans = min(nums[mid], ans);
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    // vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    vector<int> nums = {4,5,6,7,0,1,2};
    Solution obj;
    cout << "Smallest element in the rotated sorted array is: " << obj.findMin(nums);
    return 0;
}