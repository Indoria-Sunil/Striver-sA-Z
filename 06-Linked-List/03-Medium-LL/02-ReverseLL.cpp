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
    Node *reversingLinkedList(Node *head)
    {
        Node *rev = NULL;
        Node *temp = head;
        Node *helper;
        while (temp)
        {
            helper = temp->next;
            temp->next = rev;
            rev = temp;
            temp = helper;
        }
        return rev;
    }
};

int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node *head = creatingLinkedList(arr);
    cout << "Before Reversing: ";
    printingLL(head);
    Solution obj;
    head = obj.reversingLinkedList(head);
    cout << "\nAfter Reversing: ";
    printingLL(head);
    return 0;
}