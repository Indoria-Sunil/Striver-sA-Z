#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class FirstAndLast
{
private:
public:
    int findingLowerBound(vector<int> nums, int target)
    {
        int first = -1;
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target)
            {
                first = mid;
                high = mid - 1;
            }

            else
            {
                low = mid + 1;
            }
        }
        return first;
    }

    int findingUpperBound(vector<int> nums, int target)
    {
        int last = -1;
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] > target)
            {
                last = mid;
                high = mid - 1;
            }

            else
            {
                low = mid + 1;
            }
        }
        return last;
    }

    pair<int, int> getFirstAndLast(vector<int> nums, int target)
    {
        int first = findingLowerBound(nums, target);
        if (first == -1)
            return {-1, -1};
        else
            return {first, findingUpperBound(nums, target) - 1};
    }
};

int main()
{
    vector<int> nums = {3, 4, 4, 7, 8, 10};
    int target;
    cout << "Enter the number: ";
    cin >> target;

    FirstAndLast obj;
    pair<int, int> ans = obj.getFirstAndLast(nums, target);
    cout << "The first & Last occurences indexes are: " << ans.first << " " << ans.second;

    return 0;
}