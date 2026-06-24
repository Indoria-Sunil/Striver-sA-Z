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

void printingLL(Node *head)
{
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL";
}

class Solution
{
public:
    Node *reverseLL(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *newHead = reverseLL(head->next);
        Node *front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
    Node *addingOneToLLBrute(Node *head)
    {
        head = reverseLL(head);
        Node *temp = head;
        int carry = 1;

        while (temp)
        {
            temp->data = temp->data + carry;
            if (temp->data < 10)
            {
                carry = 0;
                break;
            }
            else
            {
                temp->data = 0;
                carry = 1;
            }
            temp = temp->next;
        }

        if (carry == 1)
        {
            Node *newNode = new Node(1);
            head = reverseLL(head);
            newNode->next = head;
            return newNode;
        }
        head = reverseLL(head);
        return head;
    }
    int helper(Node *temp)
    {
        if (temp == NULL)
            return 1;
        int carry = helper(temp->next);
        temp->data = temp->data + carry;
        if (temp->data < 10)
            return 0;
        temp->data = 0;
        return 1;
    }
    Node *addingOneToLLOptimal(Node *head)
    {
        int carry = helper(head);
        if (carry == 1)
        {
            Node *newNode = new Node(1);
            newNode->next = head;
            return newNode;
        }
        return head;
    }
};

int main()
{
    vector<int> arr = {2, 5, 8, 7};
    // vector<int> arr = {9, 9, 9, 9, 9};
    Node *head = creatingLinkedList(arr);
    cout << "Linked List Before: ";
    printingLL(head);
    Solution obj;
    head = obj.addingOneToLLBrute(head);
    // head = obj.addingOneToLLOptimal(head);
    cout << "\nLinked List After: ";
    printingLL(head);

    return 0;
}