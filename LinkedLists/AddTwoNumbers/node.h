#include <iostream>

#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int data;
    Node *next;

    Node();
    Node(int);
    Node(int, Node *);
};

Node::Node()
{
    data = 0;
    next = NULL;
}

Node::Node(int data)
{
    this->data = data;
    this->next = NULL;
}

Node::Node(int data, Node *next)
{
    this->data = data;
    this->next = NULL;
}

#endif
