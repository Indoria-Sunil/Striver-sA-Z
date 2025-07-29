#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// //-----------Brute Force----------//
// int findingLargestElement(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     return nums[nums.size() -2];
// }


// //-----------Better Approach----------//
// int findingLargestElement(vector<int> &nums)
// {
//     int smaller = INT_MAX;
//     int larger = INT_MIN;
//     int secondLargest = -1;

//     if(nums.size() == 0 || nums.size() == 1) return secondLargest;

//     for(auto it : nums)
//     {
//         if(it > larger) larger = it;
//         if(it < smaller) smaller = it;
//     }
//     cout<<"Larger is: "<<larger<<endl;
//     cout<<"Smaller is: "<<smaller<<endl;
//     for(auto it : nums)
//     {
//         if(it > smaller && it < larger) secondLargest = it;
//     }
//     return secondLargest;
// }


//---------------Optimal Approach-------------//
int findingLargestElement(vector<int> nums)
{
    int largest = INT_MIN;
    int secondLarge = -1;
    for(auto it : nums)
    {
        if (it > largest)
        {
            secondLarge = largest;
            largest = it;
        } 
        else if(it > secondLarge) secondLarge = it;    
    }
    return secondLarge;
}

int main()
{
    vector<int> nums = {2, 5, 1, 3, 0};
    cout << "The Second largest element in the array is: " << findingLargestElement(nums);
    return 0;
}