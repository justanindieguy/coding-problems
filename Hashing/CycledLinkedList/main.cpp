// Write a function to check if linked list contains a cycle.

#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }

    Node *n = new Node(data);
    n->next = head;
    head = n;
}

bool containsCycle(Node *head)
{
    // Complete this function using HashTable.
    unordered_map<Node *, bool> hashTable;

    Node *temp = head;
    while (temp != NULL)
    {
        // Check if temp already exists in the HashTable.
        if (hashTable.count(temp) != 0)
            return true;

        // Insert node address in the HashTable and go to next.
        hashTable[temp] = true;
        temp = temp->next;
    }

    return false;
}

int main()
{
    Node *a = NULL;
    insertAtHead(a, 1);
    insertAtHead(a, 2);
    insertAtHead(a, 3);
    insertAtHead(a, 4);
    insertAtHead(a, 5);

    Node *temp = a->next->next->next->next;
    temp->next = a->next->next;

    if (containsCycle(a))
        cout << "Cycle found!" << endl;
    else
        cout << "Cycle not found..." << endl;

    return 0;
}
