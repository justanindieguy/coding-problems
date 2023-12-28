#include <iostream>
#include "list_node.h"

using namespace std;

void printList(ListNode *root)
{
    while (root != NULL)
    {
        cout << root->val << " ";
        root = root->next;
    }

    cout << endl;
}

ListNode *mergeTwoListsRecursive(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }

    if (list2 == NULL)
    {
        return list1;
    }

    if (list1->val <= list2->val)
    {
        list1->next = mergeTwoListsRecursive(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoListsRecursive(list1, list2->next);
        return list2;
    }
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }

    if (list2 == NULL)
    {
        return list1;
    }

    ListNode *root = list1;
    if (list1->val > list2->val)
    {
        root = list2;
        list2 = list2->next;
    }
    else
    {
        list1 = list1->next;
    }

    ListNode *temp = root;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }

        temp = temp->next;
    }

    temp->next = list1 != NULL ? list1 : list2;
    return root;
}

int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(0);
    list2->next = new ListNode(1);
    list2->next->next = new ListNode(3);
    list2->next->next->next = new ListNode(4);

    ListNode *mergedLists = mergeTwoListsRecursive(list1, list2);
    printList(mergedLists);

    return 0;
}
