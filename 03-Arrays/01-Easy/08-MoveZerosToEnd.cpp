#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// ------------- Brute ---------------//
// void movingZeros(vector<int> &nums)
// {
//     vector<int> temp;
//     for(auto it : nums)
//     {
//         if(it != 0) temp.push_back(it);
//         else continue; 
//     }
//     for(int i = 0; i < temp.size(); i++)
//     {
//         nums[i] = temp[i];
//     }
//     for(int i = temp.size(); i < nums.size(); i++)
//     {
//         nums[i] = 0;
//     }
//     for(auto it : nums) cout<<it<<" ";
// }
void movingZeros(vector<int> &nums)
{

    int j = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 0)
        {
            j = i;
            break;
        } 
    }

    if(j == -1) return;
    
    int i = j + 1;
    while (i < nums.size())
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
            
        }
        i++;
    }
    
    for(auto it : nums) cout<<it<<" ";
}



int main()
{
    vector<int> nums = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    movingZeros(nums);  
    return 0;
}