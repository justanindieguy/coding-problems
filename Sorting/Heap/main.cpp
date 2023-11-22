#include <iostream>
#include "heap.h"

using namespace std;

int main()
{
    vector<int> v1 = {5, 10, 30, 20, 35, 40, 15};

    Heap h1 = Heap(v1, false);
    h1.print();
    h1.heapSort();
    h1.print();

    cout << endl;

    Heap h2 = Heap(v1, true);
    h2.print();
    h2.heapSort();
    h2.print();

    cout << endl;

    vector<int> v2 = {7, 5, 6, 2, 3, 8};

    Heap h3 = Heap(v2, false);
    h3.print();
    h3.heapSort();
    h3.print();

    cout << endl;

    Heap h4 = Heap(v2, true);
    h4.print();
    h4.heapSort();
    h4.print();

    return 0;
}
