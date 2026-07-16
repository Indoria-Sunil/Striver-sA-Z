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
    Node *findingNewLastNode(Node *temp, int len)
    {
        int count = 1;

        while (temp)
        {
            if (count == len)
                return temp;
            count++;
            temp = temp->next;
        }
        return temp;
    }

    Node *rotateRight(Node *head, int k)
    {

        if (head == nullptr || k == 0)
            return head;

        Node *tail = head;
        int len = 1;

        while (tail->next)
        {
            tail = tail->next;
            len++;
        }

        if (k % len == 0)
            return head;
        k = k % len;

        tail->next = head;
        Node *newLastNode = findingNewLastNode(head, len - k);
        head = newLastNode->next;
        newLastNode->next = nullptr;
        return head;
    }
};

int main()
{
    // vector<int> arr = {2, 5, 8, 7};
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node *head = creatingLinkedList(arr);
    cout << "Enter the value of rotation time: ";
    int k;
    cin >> k;

    Solution obj;
    head = obj.rotateRight(head, k);
    printingLL(head);

    return 0;
}