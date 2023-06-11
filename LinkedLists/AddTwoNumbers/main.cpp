#include <iostream>

#include "node.h"
#include "linked_list.h"

using namespace std;

LinkedList addTwoNumbers(Node *n1, Node *n2)
{
    int sum = 0;
    LinkedList resultList;
    while (n1 != NULL || n2 != NULL || sum != 0)
    {
        if (n1 != NULL)
        {
            sum += n1->data;
            n1 = n1->next;
        }

        if (n2 != NULL)
        {
            sum += n2->data;
            n2 = n2->next;
        }

        resultList.insertNode(sum % 10);
        sum /= 10;
    }

    return resultList;
}

int main()
{
    LinkedList l1, l2;

    l1.insertNode(2);
    l1.insertNode(4);
    l1.insertNode(3);

    l2.insertNode(5);
    l2.insertNode(6);
    l2.insertNode(4);

    l1.printList();
    l2.printList();

    LinkedList result = addTwoNumbers(l1.getHead(), l2.getHead());
    result.printList();

    return 0;
}
