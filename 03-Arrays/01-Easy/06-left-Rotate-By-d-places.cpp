#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// // ------------- Brute Force ------------//
// void rotationByDPlaces(vector<int> &nums, int d)
// {
//     d = d % nums.size();
//     for (int j = 0; j < d; j++)
//     {
//         int temp = nums[0];
//         int i;
//         for (i = 0; i < nums.size() - 1; i++)
//         {
//             nums[i] = nums[i + 1];
//         }
//         nums[i] = temp;
//     }
//     for (auto it : nums)
//     {
//         cout << it << " ";
//     }
// }

// // --------- Better ----------//
// void rotationByDPlaces(vector<int> &v, int d)
// {
//     d = d % v.size();
//     int temp[d];
//     for (int i = 0; i < d; i++)
//     {
//         temp[i] = v[i];
//     }
//     for (int i = d; i < v.size(); i++)
//     {
//         v[i - d] = v[i];
//     }

//     for (int i = v.size() - d; i < v.size(); i++)
//     {
//         v[i] = temp[i - (v.size() - d)];
//     }
//     for (auto it : v)
//     {
//         cout << it << " ";
//     }
// }



// ------------ Optimal --------------//
void rotationByDPlaces(vector<int> &nums, int d)
{
    d = d % nums.size();
    reverse(nums.begin(), nums.begin() + d);
    reverse(nums.begin() + d, nums.end());
    reverse(nums.begin(), nums.end());

    for (auto it : nums)
    {
        cout << it << " ";
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    int d;
    cout << "Enter the d places: ";
    cin >> d;
    rotationByDPlaces(v, d);

    return 0;
}