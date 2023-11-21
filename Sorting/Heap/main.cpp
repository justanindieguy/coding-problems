#include <iostream>
#include "heap.h"

using namespace std;

int main()
{
    vector<int> v = {30, 15, 20, 5, 10, 12, 6, 40, 4};
    Heap h = Heap(v);
    h.print();

    h.heapSort();
    h.print();

    return 0;
}
