#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &bloomDay, int mid, int m, int k)
    {
        int count = 0;
        int ans = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= mid)
            {
                count++;
            }
            else
            {
                ans += count / k;
                count = 0;
            }
        }
        ans += count / k;
        return ans >= m;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {

        int n = bloomDay.size();
        long long val = m * 1LL * k * 1LL;
        if (val > n)
            return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(bloomDay, mid, m, k))
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return low;
    }
};

int main()
{
    // vector<int> bloomDay = {1, 10, 3, 10, 2};
    vector<int> bloomDay = {7, 7, 7, 7, 12, 7, 7};
    int m, k;
    cout << "Enter the no. of Bouquet: ";
    cin >> m;
    cout << "Enter the number of adjacent flower: ";
    cin >> k;
    Solution obj;
    cout << "Minimum Number of Days to Make m Bouquets : " << obj.minDays(bloomDay, m, k);
    return 0;
}