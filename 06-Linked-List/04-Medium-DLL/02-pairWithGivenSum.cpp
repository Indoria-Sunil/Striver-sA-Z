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

    for (int i = 1; i < nums.size();i++)
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

    vector<pair<int, int>> findingPair(Node* head, int sum)
    {
        
        vector<pair<int,int>> ans;
        
        if(head == nullptr) return ans;

        Node* front = head;
        Node* tail = head;

        while (tail->next)
        {
            tail = tail->next;            
        }

        while (front->data < tail->data)
        {
            if(front->data + tail->data == sum)
            {
                ans.push_back({front->data, tail->data});
                front = front->next;
                tail = tail->back;
            }
            else if (front->data + tail->data < sum)
            {
                front = front->next;
            }
            else
            {
                tail = tail->back;
            }
        }
        return ans;       

    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head = creatingDoublyLL(nums);
    // printingDLL(head);
    Solution obj;
    vector<pair<int,int>> ans = obj.findingPair(head, 8);

    for(auto it : ans)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }


    return 0;
}