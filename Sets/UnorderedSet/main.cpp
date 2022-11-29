#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    // Set is just a collection of keys
    unordered_set<int> s{1, 2, 3, 8, 11, 15, 0};

    // Insert - O(1)
    s.insert(111);

    // Delete or erase - O(1)
    s.erase(11);

    int key;
    cout << "Enter the key you're lookin' for: ";
    cin >> key;

    // Search or find - O(1)
    if (s.find(key) != s.end())
        cout << key << " is present!" << endl;
    else
        cout << key << " not found..." << endl;

    // Print all the elements of unordered_set
    for (auto el : s)
        cout << el << " ";

    cout << endl;

    return 0;
}
