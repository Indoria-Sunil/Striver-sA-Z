#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return true;

            if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
                continue;
            }

            else if (nums[low] <= nums[mid])
            {
                if (target >= nums[low] && target <= nums[mid])
                {
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            else
            {
                if (target >= nums[mid] && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target;
    cout << "Enter the number to be searched: ";
    cin >> target;
    Solution obj;
    bool ans = obj.search(nums, target);
    if (ans)
        cout << "Element Found!";
    else
        cout << "Element Not Found :/";
    return 0;
}