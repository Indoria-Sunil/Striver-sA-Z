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
    if (arr.empty())
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
    cout<<"NULL";
}


class Solution
{
public:
    Node *deletingNode(int data, Node *head)
    {
        
        if(head == NULL) return nullptr;
        if(head->data == data) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        Node* curr = head;
        while (curr->next)
        {
            if(curr->next->data == data) 
            {
                Node* nodeToDelete = curr->next;
                curr->next = curr->next->next;
                delete nodeToDelete;
                break;
            }
            curr = curr->next;
        }
        return head;        
    }
};


int main()
{

    vector<int> arr = {2, 5, 8, 7};
    Node *head = creatingLinkedList(arr);
    cout << "LinkedList before addition of Node ";
    printingLL(head);

    Solution obj;
    head = obj.deletingNode(5, head);
    cout << "\nLinkedList after addition of Node ";
    printingLL(head);

    return 0;
}