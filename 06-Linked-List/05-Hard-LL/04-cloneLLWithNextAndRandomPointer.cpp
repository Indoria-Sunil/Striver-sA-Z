#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *random;

    Node(int value) {
        data = value;
        next = NULL;
        random = NULL;
    }
};

class LinkedList {
private:
    Node *head;
    Node *nodes[10];

public:
    LinkedList() {
        head = NULL;
    }

    // Create a linked list of 10 nodes
    void createList() {
        Node *temp = NULL;

        for (int i = 0; i < 10; i++) {
            nodes[i] = new Node(i + 1);

            if (head == NULL) {
                head = nodes[i];
                temp = head;
            } else {
                temp->next = nodes[i];
                temp = temp->next;
            }
        }
    }

    // Assign random pointers
    void assignRandomPointers() {
        srand(time(0));

        for (int i = 0; i < 10; i++) {
            int index = rand() % 10;
            nodes[i]->random = nodes[index];
        }
    }

    // Display the list
    void display() {
        Node *temp = head;

        cout << "Linked List with Random Pointers\n\n";

        while (temp != NULL) {
            cout << "Data: " << temp->data;

            if (temp->next != NULL)
                cout << " | Next: " << temp->next->data;
            else
                cout << " | Next: NULL";

            if (temp->random != NULL)
                cout << " | Random: " << temp->random->data;
            else
                cout << " | Random: NULL";

            cout << endl;

            temp = temp->next;
        }
    }

    // Destructor
    ~LinkedList() {
        Node *temp = head;

        while (temp != NULL) {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
    }
};

int main() {
    LinkedList list;

    list.createList();
    list.assignRandomPointers();
    list.display();

    return 0;
}