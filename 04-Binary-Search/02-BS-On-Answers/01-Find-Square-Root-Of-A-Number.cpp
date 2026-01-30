#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findingSquareRoot(int number)
    {
        if (number == 1)
            return 1;
        int low = 1, high = number;
        int ans;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;

            if (mid * mid <= number)
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};

int main()
{
    int number;
    cout << "Enter the number: ";
    cin >> number;
    Solution obj;
    cout << "The sqaure root of the given number is: " << obj.findingSquareRoot(number);

    return 0;
}