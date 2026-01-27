#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int ans = INT_MAX;
        int index = -1;
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
                continue;
            }

            if (nums[low] <= nums[mid])
            {
                if (nums[low] < ans)
                {
                    index = low;
                    ans = nums[low];
                }
                low = mid + 1;
            }
            else
            {
                if (nums[mid] < ans)
                {
                    index = mid;
                    ans = nums[mid];
                }
                high = mid - 1;
            }
        }
        return index;
    }
};

int main()
{
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    // vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    Solution obj;
    cout << "Number of times the sorted array rotated is: " << obj.findMin(nums);
    return 0;
}