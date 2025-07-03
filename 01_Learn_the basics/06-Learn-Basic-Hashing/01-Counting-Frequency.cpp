#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//---------- Brute Force -----------//
void bruteCounting(vector<int> v)
{
    vector<bool> vis(v.size(), false);
    for (int i = 0; i < v.size(); i++)
    {
        if (vis[i] == true)
            continue;

        int count = 1;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] == v[i])
            {
                vis[j] = true;
                count++;
            }
        }
        cout << v[i] << " -> " << count << ", ";
    }
}

void mapCounting(vector<int> v)
{
    unordered_map<int, int> mp;
    for(auto it : v)
    {
        mp[it]++;
    }

    for(auto it : mp)
    {
        cout<<it.first<<" -> "<<it.second<<", ";
    }
}

int main()
{
    cout<<"Welcome to frequency counter: \n";
    vector<int> v = {10, 5, 5, 10, 2, 3, 3, 2, 7, 5, 1};
    bruteCounting(v);
    cout<<endl;
    mapCounting(v);
    return 0;
}