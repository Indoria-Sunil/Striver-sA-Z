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
    Node *deleteMiddle(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *temp = slow->next;
        slow->next = slow->next->next;
        delete (temp);
        return head;
    }
};

int main()
{
    vector<int> arr = {2, 5, 7, 9, 10};
    Node *head = creatingLinkedList(arr);
    cout << "Linked List before: ";
    printingLL(head);

    Solution obj;
    head = obj.deleteMiddle(head);
    cout << "\nLinked List after: ";
    printingLL(head);


    return 0;
}