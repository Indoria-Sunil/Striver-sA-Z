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
    Node *reversingLinkedListBrute(Node *head)
    {
        if(!head) return head;
        Node *temp = head;
        stack<int> st;
        while (temp)
        {
            st.push(temp->data);
            temp = temp->next;
        }

        Node *headRev = NULL;
        Node *tail = NULL;

        while (!st.empty())
        {
            int data = st.top();
            st.pop();
            Node *newNode = new Node(data);
            if (!headRev)
            {
                headRev = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
        return headRev;
    }
};

int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node *head = creatingLinkedList(arr);
    Solution obj;
    cout << "Before Reversing: ";
    printingLL(head);
    head = obj.reversingLinkedListBrute(head);
    cout << "\nAfter Reversing: ";
    printingLL(head);
    return 0;
}