#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int checkingMid(int mid, vector<int> &piles)
    {
        int totalHours = 0;
        for (auto it : piles)
        {
            totalHours += ceil(double(it) / double(mid));
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int> &piles, int hours)
    {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int totalHours = checkingMid(mid, piles);
            if (totalHours <= hours)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return low; // low will always be at possible answer
    }
};

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int hours;
    cout << "Enter the value of hours: ";
    cin >> hours;
    Solution obj;
    cout << obj.minEatingSpeed(piles, hours);

    return 0;
}