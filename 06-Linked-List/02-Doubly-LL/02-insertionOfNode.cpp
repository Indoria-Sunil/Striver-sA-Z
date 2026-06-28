#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *back;
    Node(int data, Node *next, Node *back)
    {
        this->data = data;
        this->next = next;
        this->back = back;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->back = NULL;
    }
};

Node *creatingDoublyLL(vector<int> &nums)
{
    Node *head = new Node(nums[0]);
    Node *prev = head;

    for (int i = 1; i < nums.size(); i++)
    {
        Node *temp = new Node(nums[i], NULL, prev);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }
    return head;
}

void printingDLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
}

class Solution
{
public:
    Node *insertionBeforeHead(Node *head, int val)
    {
        Node *newHead = new Node(val);
        newHead->next = head;
        head->back = newHead;
        head = newHead;
        return head;
    }

    Node *insertionBeforeTail(Node *head, int val)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        if (head->next == nullptr)
        {
            return insertionBeforeHead(head, val);
        }

        Node *tail = head;
        while (tail->next)
        {
            tail = tail->next;
        }

        Node *prev = tail->back;
        Node *newNode = new Node(val);
        prev->next = newNode;
        tail->back = newNode;
        newNode->back = prev;
        newNode->next = tail;

        return head;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head = creatingDoublyLL(nums);
    cout << "Linked List before: ";
    printingDLL(head);
    Solution obj;
    // head = obj.insertionBeforeHead(head, 0);
    head = obj.insertionBeforeTail(head, 89);
    cout << "\nLinked List  After: ";
    printingDLL(head);

    return 0;
}