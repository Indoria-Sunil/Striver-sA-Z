#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &nums, int mid, int threshold)
    {
        long long sum = 0;
        for (auto it : nums)
        {
            sum += (it + mid - 1) / mid;
            if (sum > threshold)
                return false;
        }
        return true;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int n = nums.size();
        // if there is no divisor then to return -1;
        //  if(n > threshold) return -1;

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (isPossible(nums, mid, threshold))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 2, 5, 9};
    int threshold;
    cout << "Enter the value of threshold: ";
    cin >> threshold;
    cout << "The smallest divisor is: " << obj.smallestDivisor(nums, threshold);

    return 0;
}