#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *creatingLinkedList(vector<int> arr)
{
    if (arr.size() == 0)
        return NULL;
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

class Solution
{
public:
    Node *addTwoNumbers(Node *l1, Node *l2)
    {
        Node *dummy = new Node();
        Node *temp = dummy;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int sum = 0;
            if (l1)
            {
                sum += l1->data;
                l1 = l1->next;
            }

            if (l2)
            {
                sum += l2->data;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            Node *node = new Node(sum % 10);
            temp->next = node;
            temp = temp->next;
        }
        return dummy->next;
    }
};