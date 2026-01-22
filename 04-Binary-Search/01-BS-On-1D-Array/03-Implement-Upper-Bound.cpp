#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class upperBoundFinder
{
private:
public:
    int findingUpperBound(vector<int> nums, int target)
    {
        int ans = nums.size();
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] > target)
            {
                ans = mid;
                high = mid - 1;
            }

            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {2, 3, 6, 7, 8, 8, 11, 11, 11, 12};
    int target;
    cout << "Enter the number: ";
    cin >> target;

    upperBoundFinder obj;
    int index = obj.findingUpperBound(nums, target);

    cout << "Upper Bound index is: " << index;

    return 0;
}