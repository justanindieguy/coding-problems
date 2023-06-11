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
    void deleteNode(int);
    void printList();
    Node *getHead();
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
        temp = temp->next;
    }

    temp->next = newNode;
}

void LinkedList::deleteNode(int nodeOffset)
{
    if (head == NULL)
        return;

    int length = 0;
    Node *temp1 = head, *temp2 = NULL;

    while (temp1 != NULL)
    {
        temp1 = temp1->next;
        length++;
    }

    if (length < nodeOffset)
    {
        cout << "Index out of range" << endl;
    }

    temp1 = head;
    if (nodeOffset == 0)
    {
        head = head->next;
        delete temp1;
        return;
    }

    while (nodeOffset > 0)
    {
        temp2 = temp1;
        temp1 = temp1->next;
        nodeOffset--;
    }

    temp2->next = temp1->next;
    delete temp1;
}

void LinkedList::printList()
{
    if (head == NULL)
        return;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL)
            cout << temp->data << ", ";
        else
            cout << temp->data;

        temp = temp->next;
    }

    cout << endl;
}

Node *LinkedList::getHead()
{
    return head;
}

#endif
