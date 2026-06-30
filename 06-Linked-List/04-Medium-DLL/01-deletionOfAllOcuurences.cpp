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
    Node *deletionOFAllOccurences(Node *head, int k)
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            if (temp->data == k)
            {
                if (temp == head)
                    head = head->next;
                Node *prevNode = temp->back;
                Node *nextNode = temp->next;
                if (prevNode)
                    prevNode->next = nextNode;
                if (nextNode)
                    nextNode->back = prevNode;
                free(temp);
                temp = nextNode;
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }
};

int main()
{
    vector<int> nums = {1, 2, 1, 4, 5, 1, 7, 8, 1};
    Node *head = creatingDoublyLL(nums);
    cout << "Linked List before: ";
    printingDLL(head);
    Solution obj;
    head = obj.deletionOFAllOccurences(head, 1);
    cout << "\nLinked List After: ";
    printingDLL(head);

    return 0;
}