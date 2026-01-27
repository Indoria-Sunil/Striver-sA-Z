#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSingleElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1;
        int high = nums.size() - 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
            {
                return nums[mid];
            }

            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    Solution obj;
    cout << "Single element in the sorted array is: " << obj.findSingleElement(nums);
    return 0;
}