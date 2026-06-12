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
    Node *findingMiddleNode(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;
        Node *temp = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node *mergingLL(Node *list1, Node *list2)
    {
        Node *dummy = new Node(-1);
        Node *temp = dummy;
        while (list1 && list2)
        {
            if (list1->data < list2->data)
            {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        if (list1)
            temp->next = list1;
        else
            temp->next = list2;
        return dummy->next;
    }

    Node *sortList(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *middle = findingMiddleNode(head);
        Node *right = middle->next;
        middle->next = NULL;
        Node *left = head;

        left = sortList(left);
        right = sortList(right);
        return mergingLL(left, right);
    }
};

int main()
{
    vector<int> arr = {2, 5, 8, 7, 1, 3, 6, 4, 9};
    Node *head = creatingLinkedList(arr);
    Solution obj;
    head = obj.sortList(head);
    printingLL(head);

    return 0;
}