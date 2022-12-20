#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> &v);

int main()
{
    // Demo Vector
    vector<int> arr = {1, 2, 10, 12, 15};

    // Removes the last element in the array
    arr.pop_back();

    // Push_back appends an element at the end of the array in O(1)
    arr.push_back(16);

    // Print all the elements
    cout << "---------------------" << endl;
    cout << "Printing arr" << endl;
    print_vector(arr);

    // Fill constructor (fills an array with the same element)
    vector<int> visited(10, 0);

    cout << "---------------------" << endl;
    cout << "Printing visited" << endl;
    print_vector(visited);

    return 0;
}

void print_vector(vector<int> &v)
{
    // Print all the elements of a vector
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        if (i < size - 1)
        {
            cout << v[i] << ", ";
            continue;
        }

        cout << v[i] << endl;
    }

    // Size of the vector
    cout << "Size: " << v.size() << endl;

    // Capacity of the vector
    cout << "Capacity: " << v.capacity() << endl;
}
