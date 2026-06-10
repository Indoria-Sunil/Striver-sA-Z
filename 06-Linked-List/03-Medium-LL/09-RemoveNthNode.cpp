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

class Solution {
public:
    Node* removeNthFromEnd(Node* head, int n) {

        Node* dummy = new Node(0);
        dummy->next = head;

        Node* fast = dummy;
        Node* slow = dummy;

        for(int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        Node* del = slow->next;

        slow->next = slow->next->next;

        delete del;

        return dummy->next;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head = creatingLinkedList(arr);
    Solution obj;
    head = obj.removeNthFromEnd(head, 9);
    printingLL(head);

    return 0;
}