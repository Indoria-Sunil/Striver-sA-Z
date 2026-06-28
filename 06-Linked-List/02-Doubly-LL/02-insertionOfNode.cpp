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
        if (head != nullptr)
        {
            newHead->next = head;
            head->back = newHead;
        }

        return newHead;
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

    Node *insertionBeforeKthNode(Node *head, int val, int k)
    {
        if (head == nullptr)
            return nullptr;

        if (k == 1)
            return insertionBeforeHead(head, val);

        Node *temp = head;
        int count = 1;

        while (temp && count < k)
        {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr)
            return head; // invalid k

        Node *prev = temp->back;
        Node *newNode = new Node(val, temp, prev);

        prev->next = newNode;
        temp->back = newNode;

        return head;
    }
    
    void insertionBeforeGivenNode(Node* node, int val)
    {
        Node* prev = node->back;
        Node* temp = new Node(val, node, prev);
        prev->next = temp;
        node->back = temp;
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
    // head = obj.insertionBeforeTail(head, 89);
    // head = obj.insertionBeforeKthNode(head, 89, 9);
    obj.insertionBeforeGivenNode(head->next,10);
    cout << "\nLinked List  After: ";
    printingDLL(head);

    return 0;
}