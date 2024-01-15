#include <iostream>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next = NULL;

    ListNode(int val) { this->val = val; }
};

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *curr = head, *next = head->next;

    while (next != NULL)
    {
        if (curr->val != next->val)
        {
            curr = curr->next;
            curr->val = next->val;
        }

        next = next->next;
    }

    curr->next = NULL;

    return head;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(3);

    head = deleteDuplicates(head);
    printList(head);

    return 0;
}
