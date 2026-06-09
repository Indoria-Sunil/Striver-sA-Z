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

class Solution
{
public:
    Node *oddEvenListBrute(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        vector<int> nums;
        Node *temp = head;
        while (temp && temp->next)
        {
            nums.push_back(temp->data);
            temp = temp->next->next;
        }
        if (temp)
            nums.push_back(temp->data);

        temp = head->next;

        while (temp && temp->next)
        {
            nums.push_back(temp->data);
            temp = temp->next->next;
        }
        if (temp)
            nums.push_back(temp->data);
        temp = head;

        int i = 0;
        while (temp)
        {
            temp->data = nums[i++];
            temp = temp->next;
        }
        return head;
    }

    Node *oddEvenListOptimal(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *odd = head;
        Node *even = head->next;
        Node *evenHead = head->next;

        while (even != NULL && even->next != NULL)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
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

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node *head = creatingLinkedList(arr);
    cout << "Linked List before: ";
    printingLL(head);
    Solution obj;
    // head = obj.oddEvenListBrute(head);
    head = obj.oddEvenListOptimal(head);
    cout << "\nLinked List after: ";
    printingLL(head);

    return 0;
}
