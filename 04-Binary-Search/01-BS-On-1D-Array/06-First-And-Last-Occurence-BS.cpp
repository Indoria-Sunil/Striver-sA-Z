#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class FirstAndLast
{
private:
public:
    int findingFirstOccurence(vector<int> nums, int target)
    {
        int first = -1;
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                first = mid;
                high = mid - 1;
            }

            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return first;
    }

    int findingLastOccurence(vector<int> nums, int target)
    {
        int last = -1;
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                last = mid;
                low = mid + 1;
            }

            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return last;
    }

    pair<int, int> getFloorAndCeil(vector<int> nums, int target)
    {
        int first = findingFirstOccurence(nums, target);
        if(first == -1) return {-1, -1};
        else return {first, findingLastOccurence(nums, target)};
    }
};

int main()
{
    vector<int> nums = {3, 4, 4, 7, 8, 10};
    int target;
    cout << "Enter the number: ";
    cin >> target;

    FirstAndLast obj;
    pair<int, int> ans = obj.getFloorAndCeil(nums, target);
    cout << "The first & Last occurences indexes are: " << ans.first << " " << ans.second;

    return 0;
}