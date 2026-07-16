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
    Node *removingDuplicates(Node *head)
    {
        Node *temp = head;
        Node *nextNode;

        {
            nextNode = temp->next;

            while (nextNode && nextNode->data == temp->data)
            {
                nextNode = nextNode->next;
            }
            temp->next = nextNode;
            if (nextNode)
                nextNode->back = temp;
            temp = temp->next;
        }
        return head;
    }
};

int main()
{
    vector<int> nums = {1, 1, 3, 3, 4, 5, 6, 6, 7, 8, 9, 9};
    Node *head = creatingDoublyLL(nums);
    printingDLL(head);
    Solution obj;
    head = obj.removingDuplicates(head);
    cout<<endl;
    printingDLL(head);
    return 0;
}