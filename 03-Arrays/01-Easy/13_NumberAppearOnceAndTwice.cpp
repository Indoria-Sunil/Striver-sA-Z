#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);




// -------------- Optimal Approach (Using XOR) -----------------//
// Time Complexity: O(N)
// Space Complexity: O(1)
int getSingleElement(const vector<int> &arr) {
    int result = 0;
    for (int num : arr) {
        result ^= num; 
    }
    return result;
}



int main() {
    fast_io;
    
    // Your code goes here
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << ans << "\n";
    
    return 0;
}