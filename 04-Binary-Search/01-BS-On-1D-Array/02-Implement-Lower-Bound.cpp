#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class lowerBoundFinder
{
private:
public:
    int findingLowerBound(vector<int> nums, int target)
    {
        int ans = nums.size();
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target)
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
    vector<int> nums = {3, 5, 8, 15, 19};
    int target;
    cout << "Enter the number: ";
    cin >> target;

    lowerBoundFinder obj;
    int index = obj.findingLowerBound(nums, target);

    cout << "Lower Bound index is: " << index;

    return 0;
}