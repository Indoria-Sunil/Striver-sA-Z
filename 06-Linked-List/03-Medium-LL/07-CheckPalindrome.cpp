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

Node *reverseLinkedList(Node *head)
{
    if (head->next == NULL || head == NULL)
        return head;
    Node *revHead = reverseLinkedList(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;
    return revHead;
}

class Solution
{
public:
    bool isPalindromeBrute(Node *head)
    {
        Node *temp = head;
        stack<int> st;
        while (temp)
        {
            st.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while (temp)
        {
            int element = st.top();
            st.pop();
            if (temp->data != element)
                return false;
            temp = temp->next;
        }
        return true;
    }

    bool isPalindromeOptimal(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        if (head == NULL || head->next == NULL)
            return true;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *newHead = reverseLinkedList(slow->next);
        Node *first = head;
        Node *second = newHead;

        while (second != NULL)
        {
            if (first->data != second->data)
            {
                reverseLinkedList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLinkedList(newHead);
        return true;
    }
};

int main()
{
    vector<int> arr = {2, 5, 8, 7, 8, 5, 2};
    Node *head = creatingLinkedList(arr);
    // printingLL(head);
    Solution obj;
    cout << obj.isPalindromeOptimal(head);
    cout << obj.isPalindromeBrute(head);

    return 0;
}