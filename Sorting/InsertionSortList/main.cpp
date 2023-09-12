/*
 * Given the head of a singly linked list, sort the list using insertion sort,
 * and return the sorted list's head.
 *
 * The steps of insertion sort algorithm:
 *   1. Insertion sort iterates, consuming one input element each repetition and
 *      growing a sorted output list.
 *   2. At each iteration, insertion sort removes one element from the input
 *      data, find the location it belongs with the sorted list and inserts it
 *      there.
 *   3. It repeats until no input element remain.
 */
#include <cstdlib>
#include <iostream>
#include <vector>
#include "linked_list.h"

using namespace std;

void insertionSort(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int currentIdx = i;
        while (currentIdx > 0 && v[currentIdx - 1] > v[currentIdx])
        {
            swap(v[currentIdx], v[currentIdx - 1]);
            currentIdx--;
        }
    }
}

int main()
{
    LinkedList l;
    l.insertNode(-1);
    l.insertNode(5);
    l.insertNode(3);
    l.insertNode(4);
    l.insertNode(0);

    l.printList();

    l.insertionSort();

    l.printList();

    return 0;
}
