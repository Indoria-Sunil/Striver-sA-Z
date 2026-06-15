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
    Node *getIntersectionNodeBrute(Node *headA, Node *headB)
    {
        unordered_set<Node *> st;

        while (headA)
        {
            st.insert(headA);
            headA = headA->next;
        }

        while (headB)
        {
            if (st.count(headB))
                return headB;

            headB = headB->next;
        }

        return NULL;
    }

    Node *getIntersectionNodeBetter(Node *headA, Node *headB)
    {
        int n1 = 0;
        int n2 = 0;

        Node *temp = headA;

        while (temp)
        {
            n1++;
            temp = temp->next;
        }

        temp = headB;

        while (temp)
        {
            n2++;
            temp = temp->next;
        }

        int diff = abs(n1 - n2);
        Node *ptr1 = headA;
        Node *ptr2 = headB;

        if (n1 > n2)
        {
            while (diff--)
            {
                ptr1 = ptr1->next;
            }
        }
        else
        {
            while (diff--)
            {
                ptr2 = ptr2->next;
            }
        }
        while (ptr1 && ptr2)
        {
            if (ptr1 == ptr2)
                return ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return NULL;
    }

    Node *getIntersectionNodeOptimal(Node *headA, Node *headB)
    {

        if (headA == NULL || headB == NULL)
            return NULL;
        Node *temp1 = headA;
        Node *temp2 = headB;

        while (temp1 != temp2)
        {
            temp1 = (temp1 == NULL) ? headB : temp1->next;
            temp2 = (temp2 == NULL) ? headA : temp2->next;
        }
        return temp1;
    }
};
