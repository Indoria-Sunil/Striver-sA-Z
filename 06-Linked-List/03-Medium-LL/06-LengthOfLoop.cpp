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
    int findingLength(Node *slow, Node *fast)
    {
        int counter = 1;
        fast = fast->next;

        while (fast != slow)
        {
            counter++;
            fast = fast->next;
        }
        return counter;
    }

    int findingLengthOfLoop(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return findingLength(slow, fast);
            }
        }
        return 0;
    }
};
