#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Solution
{
public:
    bool hasCycleBrute(Node *head)
    {
        map<Node *, int> mp;
        Node *temp = head;
        while (temp)
        {
            if (mp.find(temp) != mp.end())
                return true;
            mp[temp]++;
            temp = temp->next;
        }
        return false;
    }

    bool hasCycleOptimal(Node *head)
    {
        Node *fast = head;
        Node *slow = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

int main()
{

    return 0;
}