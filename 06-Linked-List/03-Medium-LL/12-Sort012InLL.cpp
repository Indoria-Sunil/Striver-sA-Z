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
    Node *sortingLinkedList(Node *head)
    {
        if (!head || !head->next)
            return head;

        Node *temp = head;
        Node *zeroHead = new Node(-1);
        Node *oneHead = new Node(-1);
        Node *twoHead = new Node(-1);
        Node *zero = zeroHead;
        Node *one = oneHead;
        Node *two = twoHead;

        while (temp)
        {
            if (temp->data == 0)
            {
                zero->next = temp;
                zero = temp;
            }
            else if (temp->data == 1)
            {
                one->next = temp;
                one = temp;
            }
            else
            {
                two->next = temp;
                two = temp;
            }
            temp = temp->next;
        }
        zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = NULL;
        temp = zeroHead->next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        return temp;
    }
};

int main()
{
    vector<int> arr = {2, 1, 2, 0, 1, 0, 1, 2, 1, 0};
    Node *head = creatingLinkedList(arr);
    cout << "Linked List before: ";
    printingLL(head);

    Solution obj;
    head = obj.sortingLinkedList(head);
    cout << "Linked List After: \n";
    printingLL(head);

    return 0;
}