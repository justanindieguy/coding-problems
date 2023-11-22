#include <iostream>
#include <vector>

#ifndef HEAP_H
#define HEAP_H

using namespace std;

class Heap
{
private:
    vector<int> heap;

public:
    Heap(vector<int> v, bool fastCreation)
    {
        heap = v;

        if (fastCreation)
        {
            heapify();
        }
        else
        {
            createOneByOne();
        }
    }

    void insert(int i);
    int remove(int i);
    void createOneByOne();
    void heapify();
    void heapSort();
    void print();
};

/**
 * @brief Insert into the Heap
 *
 * @param i index of the element (already in array) to be inserted
 */
void Heap::insert(int i)
{
    int temp = heap[i];
    while (i > 0 && temp > heap[(i - 1) / 2])
    {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    heap[i] = temp;
}

int Heap::remove(int lastInHeapIdx)
{
    int temp = heap[0],          // Element to be deleted
        x = heap[lastInHeapIdx], // Last ordered element in Heap
        i = 0,                   // Start from the root
        j = i * 2 + 1;           // Left children

    heap[0] = x; // Bring last ordered element to the root

    while (j < lastInHeapIdx)
    {
        // If right children is greater, take it as j
        if (heap[j + 1] > heap[j])
        {
            j++;
        }

        // If the parent is smaller than the greatest child, swap them
        if (heap[i] < heap[j])
        {
            swap(heap[i], heap[j]);
            i = j;
            j = i * 2 + 1;
        }
        else
        {
            break;
        }
    }

    heap[lastInHeapIdx] = temp;
    return temp;
}

void Heap::createOneByOne()
{
    int n = heap.size();

    if (n <= 1)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        insert(i);
    }
}

void Heap::heapify()
{
    int n = heap.size();

    if (n <= 1)
    {
        return;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int child = i * 2 + 1; // Left child

        // No left child, nor right child.
        if (child >= n)
        {
            continue;
        }

        int parent = i;
        while (child < n)
        {
            if (child + 1 < n && heap[child + 1] > heap[child])
            {
                child++;
            }

            if (heap[parent] < heap[child])
            {
                swap(heap[parent], heap[child]);
                parent = child;
                child = parent * 2 + 1;
            }
            else
            {
                break;
            }
        }
    }
}

void Heap::heapSort()
{
    int n = heap.size();

    if (n == 0)
    {
        return;
    }

    // After removing every element from the Heap, the array becomes sorted
    for (int i = n - 1; i >= 0; i--)
    {
        remove(i);
    }
}

void Heap::print()
{
    for (int i = 0, n = heap.size(); i < n; i++)
    {
        if (i == n - 1)
        {
            cout << heap[i] << endl;
            return;
        }

        cout << heap[i] << ", ";
    }
}

#endif
