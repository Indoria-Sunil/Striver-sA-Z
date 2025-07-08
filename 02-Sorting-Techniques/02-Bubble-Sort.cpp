#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// //---------- Brute ----------//
// void bubbleSort(vector<int> &v)
// {
//     for (int i = 0; i < v.size()-1; i++)
//     {
//         for (int j = 1; j < v.size() - i; j++)
//         {
//             if (v[j] < v[j - 1])
//             {
//                 swap(v[j], v[j - 1]);
//             }
//         }
//     }
// }


//-------- OPTIMISED -----------//
void bubbleSort(vector<int> &v)
{
    for (int i = 0; i < v.size()-1; i++)
    {
        bool flag = false;
        for (int j = 1; j < v.size() - i; j++)
        {
            if (v[j] < v[j - 1])
            {
                swap(v[j], v[j - 1]);
                flag = true;
            }
        }
        if(flag == false) break;
    }
}



int main()
{
    cout << "Welcome to Bubble Sort.\n";
    vector<int> v = {13, 46, 24, 52, 20, 9};
    cout << "Before sorting ";
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    bubbleSort(v);
    cout << "After sorting ";
    for (auto it : v)
    {
        cout << it << " ";
    }

    return 0;
}