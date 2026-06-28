#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *back;
    Node(int data, Node *next, Node *back)
    {
        this->data = data;
        this->next = next;
        this->back = back;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->back = NULL;
    }
};

Node *creatingDoublyLL(vector<int> &nums)
{
    Node *head = new Node(nums[0]);
    Node *prev = head;

    for (int i = 1; i < nums.size(); i++)
    {
        Node *temp = new Node(nums[i], NULL, prev);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }
    return head;
}

void printingDLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
}

class Solution
{
public:
    Node *deletingHeadOfDLL(Node *head)
    {
        if (head == NULL)
            return NULL;

        if (head->next == NULL)
        {
            delete head;
            return NULL;
        }

        Node *prev = head;
        head = head->next;

        head->back = NULL;
        prev->next = NULL;
        delete prev;
        return head;
    }

    Node *deletingTailOfDLL(Node *head)
    {

        if (head == NULL)
            return NULL;

        if (head->next == NULL)
        {
            delete head;
            return NULL;
        }
        Node *tail = head;
        while (tail->next)
        {
            tail = tail->next;
        }
        Node *prev = tail->back;
        prev->next = NULL;
        tail->back = NULL;
        delete tail;
        return head;
    }

    Node *deleteKthElement(Node *head, int k)
    {
        int count = 0;
        Node *temp = head;
        while (temp)
        {
            count++;
            if (count == k)
            {
                break;
            }
            temp = temp->next;
        }

        if (temp == NULL)
            return head;

        Node *front = temp->next;
        Node *prev = temp->back;

        if (front == NULL && prev == NULL)
        {
            delete temp;
            return NULL;
        }
        else if (front == NULL)
        {
            return deletingTailOfDLL(head);
        }
        else if (prev == NULL)
        {
            return deletingHeadOfDLL(head);
        }
        front->back = prev;
        prev->next = front;
        temp->back = NULL;
        temp->next = NULL;
        delete temp;

        return head;
    }


    //General implementation (handles all cases)
    Node *deleteNode(Node *head, Node *temp)
    {
        if (temp == nullptr)
            return head;

        if (temp->back)
            temp->back->next = temp->next;
        else
            head = temp->next;

        if (temp->next)
            temp->next->back = temp->back;

        delete temp;
        return head;
    }
};


int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head = creatingDoublyLL(nums);
    cout << "Linked List before: ";
    printingDLL(head);
    Solution obj;
    // head = obj.deletingHeadOfDLL(head);
    // head = obj.deletingTailOfDLL(head);
    // head = obj.deleteKthElement(head, 5);
    head = obj.deleteNode(head, head->next);
    cout << "\nLinked List After: ";
    printingDLL(head);

    return 0;
}