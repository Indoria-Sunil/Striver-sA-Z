#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

int findingMaxConsecutiveOnes(const vector<int> &nums) {
    int count = 0;
    int maxCount = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            count++;
            maxCount = max(count, maxCount);
        }
        else
        {
            count = 0;
        }   
        
    }
    
    return maxCount;
}


int main() {
    fast_io;
    
    // Your code goes here
    vector < int > nums = { 1, 1, 0, 1, 1, 1 };
    int ans = findingMaxConsecutiveOnes(nums);
    cout << ans << "\n";
    
    return 0;
}