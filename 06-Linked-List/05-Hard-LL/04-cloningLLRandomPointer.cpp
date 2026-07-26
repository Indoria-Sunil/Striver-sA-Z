#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int val)
    {
        data = val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{
public:
    Node *copyRandomListBrute(Node *head)
    {
        if(head == nullptr) return nullptr;

        unordered_map<Node *, Node *> mp;

        Node *temp = head;
        while (temp)
        {
            Node *newNode = new Node(temp->data);
            mp[temp] = newNode;
            temp = temp->next;
        }

        temp = head;
        Node *copyNode;
        while (temp)
        {
            mp[temp]->next = (temp->next) ? mp[temp->next] : nullptr;
            mp[temp]->random = (temp->random) ? mp[temp->random] : nullptr;
            temp = temp->next;
        }
        return mp[head];
    }

    Node *copyRandomListOptimal(Node *head)
    {
        if(head == nullptr) return nullptr;

        unordered_map<Node *, Node *> mp;

        Node *temp = head;
        while (temp)
        {
            Node *newNode = new Node(temp->data);
            mp[temp] = newNode;
            temp = temp->next;
        }

        temp = head;
        Node *copyNode;
        while (temp)
        {
            mp[temp]->next = (temp->next) ? mp[temp->next] : nullptr;
            mp[temp]->random = (temp->random) ? mp[temp->random] : nullptr;
            temp = temp->next;
        }
        return mp[head];
    }
};

void printList(Node* head)
{
    Node* temp = head;

    while (temp)
    {
        cout << "Node: " << temp->data;

        if (temp->random)
            cout << " | Random: " << temp->random->data;
        else
            cout << " | Random: NULL";

        cout << endl;

        temp = temp->next;
    }
}

Node* createLinkedList()
{
    // Create 10 nodes
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);
    Node *sixth = new Node(6);
    Node *seventh = new Node(7);
    Node *eighth = new Node(8);
    Node *ninth = new Node(9);
    Node *tenth = new Node(10);

    // Connect next pointers
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = tenth;

    // Connect random pointers
    head->random = fifth;         // 1 -> 5
    second->random = eighth;      // 2 -> 8
    third->random = head;         // 3 -> 1
    fourth->random = tenth;       // 4 -> 10
    fifth->random = third;        // 5 -> 3
    sixth->random = nullptr;      // 6 -> NULL
    seventh->random = seventh;    // 7 -> 7
    eighth->random = second;      // 8 -> 2
    ninth->random = sixth;        // 9 -> 6
    tenth->random = fourth;       // 10 -> 4

    return head;
}

int main()
{

    Node* head = createLinkedList();
    cout<<"Before Cloning LL is : \n\n";
    printList(head);

    Solution obj;
    Node* newHead = obj.copyRandomListBrute(head);
    cout<<"\n\nAfter cloning new LL is: \n\n";
    printList(newHead);
    return 0;
}