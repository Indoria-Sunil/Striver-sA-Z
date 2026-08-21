#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void insertInSortedOrder(stack<int> &st, int temp)
    {
        if (st.empty() || st.top() <= temp)
        {
            st.push(temp);
            return;
        }
        int element = st.top();
        st.pop();
        insertInSortedOrder(st, temp);
        st.push(element);
    }

public:
    stack<int> sortStack(stack<int> &st)
    {
        if (st.empty())
            return st;
        int temp = st.top();
        st.pop();
        sortStack(st);
        insertInSortedOrder(st, temp);
        return st;
    }
};

int main()
{

    vector<int> v = {34, 3, 31, 98, 92, 23};
    stack<int> st;
    for (int x : v)
    {
        st.push(x);
    }
    Solution obj;
    st = obj.sortStack(st);

    // Print without destroying st
    stack<int> temp = st;

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }

    return 0;
}