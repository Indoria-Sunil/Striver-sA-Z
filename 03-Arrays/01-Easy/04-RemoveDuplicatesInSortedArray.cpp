#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// // ---------- Brute Force ---------//
// void removingDuplicates(vector<int> &nums)
// {
//     set<int> st;
//     for(auto it : nums)
//     {
//         st.insert(it);
//     }
//     nums.clear();
//     for(auto& it : st)
//     {
//         nums.push_back(it);
//     }
// }


// ---------- Optimal Approach ---------//
void removingDuplicates(vector<int> &nums)
{
    for (int i = 0; i < nums.size()-1; i++)
    {
        int j = i + 1;
        while (j < nums.size())
        {
            if(nums[j] == nums[i]) nums.erase(nums.begin() + j);
            else j++;
        }        
    }    
}


int main()
{
    vector<int> nums = {1,1,2,2,2,3,3};
    cout<<"Before removing duplicates: ";
    for(auto it : nums) cout<<it<<" ";
    removingDuplicates(nums);
    cout<<"\nAfter removing duplicates: ";
    for(auto it : nums) cout<<it<<" ";
    return 0;
}