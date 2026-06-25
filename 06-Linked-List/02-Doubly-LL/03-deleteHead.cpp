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
    Node *deletingHeadOfDLL(Node *head)
    {
        if (!head || !head->next)
            return NULL;

        Node *prev = head;
        head = head->next;

        head->back = NULL;
        prev->next = NULL;
        delete prev;
        return head;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head = creatingDoublyLL(nums);
    cout<<"Linked List before: ";
    printingDLL(head);
    Solution obj;
    head = obj.deletingHeadOfDLL(head);
    cout<<"\nLinked List After: ";
    printingDLL(head);


    return 0;
}