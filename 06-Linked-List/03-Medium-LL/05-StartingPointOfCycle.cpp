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
    Node *detectCycleBrute(Node *head)
    {
        Node *temp = head;
        map<Node*, int> mp;
        while(temp)
        {
            if(mp.find(temp) != mp.end()) return temp;
            mp[temp] = 1;
            temp = temp->next;
        }
        return nullptr;
    }
    Node *detectCycle(Node *head)
    {

        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};