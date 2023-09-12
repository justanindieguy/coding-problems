#include <iostream>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

using namespace std;

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() { head = NULL; }

    void insertNode(int);
    void printList();
    void insertionSort();
};

void LinkedList::insertNode(int data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        // Get the last node to insert after it.
        temp = temp->next;
    }

    temp->next = newNode;
}

void LinkedList::printList()
{
    // In case the list is empty
    if (head == NULL)
        return;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL)
        {
            cout << temp->data << ", ";
        }
        else
        {
            cout << temp->data;
        }

        temp = temp->next;
    }

    cout << endl;
}

void LinkedList::insertionSort()
{
    if (!this->head || !this->head->next)
    {
        return;
    }

    Node *dummy = new Node(0);
    dummy->next = this->head;

    Node *prev = dummy, *curr = this->head;
    while (curr)
    {
        if ((curr->next) && (curr->next->data < curr->data))
        {
            while ((prev->next) && (prev->next->data < curr->next->data))
            {
                prev = prev->next;
            }

            Node *temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;

            // Start scanning from HEAD again in next iteration
            prev = dummy;
        }
        else
        {
            curr = curr->next;
        }
    }

    this->head = dummy->next;
}

#endif
