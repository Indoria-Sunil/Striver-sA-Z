#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void insertBottom(stack<int> &st, int temp)
    {
        if (st.empty())
        {
            st.push(temp);
            return;
        }
        int element = st.top();
        st.pop();
        insertBottom(st, temp);
        st.push(element);
    }

public:
    void reverseStack(stack<int> &st)
    {
        if (st.empty())
            return;
        int temp = st.top();
        st.pop();
        reverseStack(st);
        insertBottom(st, temp);
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
    stack<int> temp = st;
    cout<<"Stack Before Reversing: ";
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    Solution obj;
    obj.reverseStack(st);

    // Print without destroying st
    temp = st;
    cout<<"Stack After Reversing: ";

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }

    return 0;
}