#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class SearchInRotatedArray
{
public:
    int searchingInArray(vector<int> nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;

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
        return -1;
    }
};

int main()
{
    vector<int> nums = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int target;
    cout << "Enter the number to be searched: ";
    cin >> target;
    SearchInRotatedArray obj;
    int ans = obj.searchingInArray(nums, target);
    cout << ans;

    return 0;
}