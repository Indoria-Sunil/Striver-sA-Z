#include <iostream>
using namespace std;
#include <bits/stdc++.h>

struct Node
{
    int data;
    Node *next;
    Node *down;

    Node(int val)
    {
        data = val;
        next = NULL;
        down = NULL;
    }
};

class Solution
{
private:
    Node *mergingTwoSortedLists(Node *list1, Node *list2)
    {
        Node *dummyNode = new Node(-1);
        Node *res = dummyNode;

        while (list1 && list2)
        {
            if (list1->data < list2->data)
            {
                res->down = list1;
                res = list1;
                list1 = list1->down;
            }
            else
            {
                res->down = list2;
                res = list2;
                list2 = list2->down;
            }
            res->next = nullptr;
        }

        if (list1)
            res->down = list1;
        else
            res->down = list2;

        if(dummyNode->down) dummyNode->down->next = nullptr;

        return dummyNode->down;
    }

public:
    Node *flatteningLinkedListBrute(Node *head)
    {
        vector<int> nums;
        Node *row = head;

        while (row)
        {
            Node *col = row;
            while (col)
            {
                nums.push_back(col->data);
                col = col->down;
            }
            row = row->next;
        }

        sort(nums.begin(), nums.end());
        Node *temp = new Node(nums[0]);
        head = temp;
        for (int i = 1; i < nums.size(); i++)
        {
            Node *nextNode = new Node(nums[i]);
            temp->next = nextNode;
            temp = nextNode;
        }
        return head;
    }

    Node *flatteningLinkedListOptimal(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        Node *mergedHead = flatteningLinkedListOptimal(head->next);
        head = mergingTwoSortedLists(head, mergedHead);
        return head;
    }
};

void printingLLBeforeFlatten(Node *head)
{
    Node *row = head;

    while (row)
    {
        Node *col = row;
        while (col)
        {
            cout << col->data;
            col = col->down;
            if (col == nullptr)
                cout << "--> NULL";
            else
                cout << "-->";
        }
        row = row->next;
        if (row != NULL)
            cout << "\n|\n";
    }
    cout << endl;
}


void printingLLAfterFlatten(Node *head)
{
    while (head)
    {
        cout << head->data;

        if (head->down)
            cout << " -> ";

        head = head->down;
    }

    cout << " -> NULL" << endl;
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

    // Horizontal list
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Vertical list of 2
    head->next->down = new Node(10);

    // Vertical list of 1
    head->next->next->down = new Node(7);
    head->next->next->down->down = new Node(11);
    head->next->next->down->down->down = new Node(12);

    // Vertical list of 4
    head->next->next->next->down = new Node(9);

    // Vertical list of 5
    head->next->next->next->next->down = new Node(6);
    head->next->next->next->next->down->down = new Node(8);
    printingLLBeforeFlatten(head);
    Solution obj;
    // head = obj.flatteningLinkedListBrute(head);
    head = obj.flatteningLinkedListOptimal(head);
    printingLLAfterFlatten(head);

    return 0;
}
