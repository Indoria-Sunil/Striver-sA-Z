#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class FloorCeilFinder
{
private:
public:
    int findingFloorValue(vector<int> nums, int target)
    {
        int ans = nums.size();
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] <= target)
            {
                ans = nums[mid];
                low = mid + 1;
            }

            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }

    int findingCeilValue(vector<int> nums, int target)
    {
        int ans = -1;
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target)
            {
                ans = nums[mid];
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }

    pair<int, int> getFloorAndCeil(vector<int> nums, int target)
    {
        int floor = findingFloorValue(nums, target);
        int ceil = findingCeilValue(nums, target);
        return {floor, ceil};
    }
};

int main()
{
    vector<int> nums = {3, 4, 4, 7, 8, 10};
    int target;
    cout << "Enter the number: ";
    cin >> target;

    FloorCeilFinder obj;
    pair<int, int> ans = obj.getFloorAndCeil(nums, target);
    cout << "The Floor & Ceil value are: " << ans.first<<" "<<ans.second;

    return 0;
}