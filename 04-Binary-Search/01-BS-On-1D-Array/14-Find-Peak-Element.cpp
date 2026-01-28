#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findingPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (nums[0] > nums[1])
            return nums[0];
        if (nums[n - 1] > nums[n - 2])
            return nums[n - 1];

        int low = 1;
        int high = nums.size() - 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return nums[mid];
            }

            else if (nums[mid] > nums[mid - 1])
            {
                low = mid + 1;
            }
            else if (nums[mid] > nums[mid + 1])
            {
                high = mid - 1;
            }
            else
            {
                // The array contains multiple peaks and currently the mid points to somewhere between two peaks
                // So either go to left sorted or right sorted side
                low = mid + 1;
                // high = mid -1;
            }
        }
        return -1;
    }
};

int main()
{
    // vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    vector<int> nums = {1, 5, 1, 2, 1};
    Solution obj;
    cout << "Peak element in the sorted array is: " << obj.findingPeakElement(nums);
    return 0;
}