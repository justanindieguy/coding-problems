/*
 * Given a Linked List, write a function to reverse the linked list.
 *
 * Input:
 *   1 => 2 => 3 => 4 => 5
 *
 * Output:
 *   5 => 4 => 3 => 2 => 1
 */

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;

    Node(int data) { this->data = data; }
};

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

Node *reverseLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newHead = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head = reverseLinkedList(head);
    printList(head);

    return 0;
}
