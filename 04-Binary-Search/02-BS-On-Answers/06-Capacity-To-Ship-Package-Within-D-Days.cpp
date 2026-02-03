#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int mid, vector<int> &weights, int days)
    {
        int totalDays = 1;
        int total = 0;

        for (auto it : weights)
        {
            if (total + it > mid)
            {
                totalDays++;
                total = it;
                if (totalDays > days)
                    return false;
            }
            else
                total += it;
        }
        return true;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(mid, weights, days))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};

int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days;
    cout << "Enter the number of days: ";
    cin >> days;
    Solution obj;
    cout << "The least weight capacity of the ship is: " << obj.shipWithinDays(weights, days);

    return 0;
}