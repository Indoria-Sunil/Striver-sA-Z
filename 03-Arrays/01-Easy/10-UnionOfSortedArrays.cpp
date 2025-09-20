#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ------------- Brute -------------//
// void findingUnion(vector<int> nums1, vector<int> nums2)
// {
//     set<int> st;
//     for (int i = 0; i < nums1.size(); i++)
//     {
//         st.insert(nums1[i]);
//     }

//     for (int i = 0; i < nums2.size(); i++)
//     {
//         st.insert(nums2[i]);
//     }

//     for (auto it : st)
//     {
//         cout << it << " ";
//     }
// }

// ------------- Optimal --------------//
void findingUnion(vector<int> nums1, vector<int> nums2)
{
    int i = 0;
    int j = 0;
    vector<int> unionArr;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] < nums2[j])
        {
            if (unionArr.size() == 0 || unionArr.back() != nums1[i])
            {
                unionArr.push_back(nums1[i]);
            }
            i++;
        }
        else
        {
            if (unionArr.size() == 0 || unionArr.back() != nums2[j])
            {
                unionArr.push_back(nums2[j]);
            }
            j++;
        }
    }
    while (i < nums1.size())
    {
        if (unionArr.size() == 0 || unionArr.back() != nums1[i])
        {
            unionArr.push_back(nums1[i]);
        }
        i++;
    }

    while (j < nums2.size())
    {
        if (unionArr.size() == 0 || unionArr.back() != nums2[j])
        {
            unionArr.push_back(nums2[j]);
        }
        j++;
    }

    for (auto it : unionArr)
    {
        cout << it << " ";
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> nums2 = {2, 3, 4, 4, 5, 11, 12};

    findingUnion(nums1, nums2);

    return 0;
}