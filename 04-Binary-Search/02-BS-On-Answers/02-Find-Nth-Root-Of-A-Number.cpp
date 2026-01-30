#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(int mid, int number, int n)
    {
        long long ans = 1;

        for (int i = 1; i <= n; i++)
        {
            ans = ans * mid;
            if (ans > number)
                return 2;
        }
        if (ans == number)
            return 1;
        return 0;
    }
    int findingNthRoot(int number, int n)
    {
        int low = 1, high = number;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int midN = helper(mid, number, n);
            if(midN == 1) return mid;
            else if (midN == 2) high = mid - 1;
            else low = mid + 1;            
        }
        return -1;
    }
};

int main()
{
    int number, n;
    cout << "Enter the number: ";
    cin >> number;
    cout << "Enter the Nth number: ";
    cin >> n;
    Solution obj;
    cout << "The Nth root of the given number is: " << obj.findingNthRoot(number, n);
    return 0;
}