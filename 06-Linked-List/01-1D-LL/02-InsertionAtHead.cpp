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

class Solution
{
public:
    Node *addingNodeToHead(int data, Node *head)
    {
        Node *temp = new Node(data, head);
        return temp;
    }
};

void printingLL(Node *head)
{
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout<<"NULL";
}

int main()
{

    vector<int> arr = {2, 5, 8, 7};
    Node *head = creatingLinkedList(arr);
    cout << "LinkedList before addition of Node ";
    printingLL(head);

    Solution obj;
    head = obj.addingNodeToHead(1, head);
    cout << "\nLinkedList after addition of Node ";
    printingLL(head);

    return 0;
}