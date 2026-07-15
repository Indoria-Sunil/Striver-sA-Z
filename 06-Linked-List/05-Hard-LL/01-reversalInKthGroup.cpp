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
    Node *reversingLinkedList(Node *head)
    {
        Node *rev = NULL;
        Node *temp = head;
        Node *helper;
        while (temp)
        {
            helper = temp->next;
            temp->next = rev;
            rev = temp;
            temp = helper;
        }
        return rev;
    }

    Node *findingKthNode(Node *temp, int k)
    {
        k--;

        while (temp && k > 0)
        {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    Node *reverseKGroup(Node *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        Node *temp = head;
        Node *prevNode = nullptr;

        while (temp != nullptr)
        {
            Node *kthNode = findingKthNode(temp, k);

            if (kthNode == nullptr)
            {
                if (prevNode)
                    prevNode->next = temp;
                break;
            }
            Node *nextNode = kthNode->next;
            kthNode->next = nullptr;
            reversingLinkedList(temp);
            if (head == temp)
                head = kthNode;
            else
            {
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};

int main()
{
    // vector<int> arr = {2, 5, 8, 7};
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node *head = creatingLinkedList(arr);
    cout << "Enter the value of kth node: ";
    int k;
    cin >> k;

    Solution obj;
    head = obj.reverseKGroup(head, k);
    printingLL(head);

    return 0;
}