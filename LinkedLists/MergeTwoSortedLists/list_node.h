#include <iostream>

#ifndef LIST_NODE_H
#define LIST_NODE_H

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

#endif
