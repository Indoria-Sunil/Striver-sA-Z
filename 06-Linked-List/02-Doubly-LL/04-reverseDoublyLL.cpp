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
    Node *reverseDLLBrute(Node *head)
    {
        if(head == nullptr || head->next == nullptr) return head;
        stack<int> st;

        Node *temp = head;
        while (temp)
        {
            st.push(temp->data);
            temp = temp->next;
        }
        temp = head;

        while (temp)
        {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }


    Node *reverseDLLOptimal(Node *head)
    {
        Node* prev = nullptr;
        Node* current = head;

        while (current)
        {
            prev = current->back;
            current->back = current->next;
            current->next = prev;
            current = current->back;
        }
        return prev->back;
        
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head = creatingDoublyLL(nums);
    cout << "Linked List before: ";
    printingDLL(head);
    Solution obj;
    // head = obj.reverseDLLBrute(head);
    head = obj.reverseDLLOptimal(head);
    cout << "\nLinked List After: ";
    printingDLL(head);

    return 0;
}