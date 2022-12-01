#include <iostream>
#include <map>
using namespace std;

int main()
{
    // If order is important then, map is necessary
    map<string, int> menu;

    // Inser Key-Value pairs inside the HashTable - O(LogN) Operation
    menu["taco"] = 15;
    menu["colddrink"] = 20;
    menu["pozole"] = 59;
    menu["pizza"] = 89;
    menu["hamburger"] = 49;
    menu["birria"] = 99;

    // Update query - O(LogN)
    menu["pozole"] = (1 + 0.1) * menu["pozole"];

    // Deletion - O(LogN)
    menu.erase("pozole");

    // Searching inside a collection of Key-Value pairs (stored inside a HashTable)
    // O(LogN)
    string item;
    cout << "Enter the name of the product you're looking for: ";
    cin >> item;

    if (menu.count(item) == 0)
    {
        cout << item << " is not available..." << endl;
    }
    else
    {
        cout << item << " is available, and its cost is $" << menu[item] << endl;
    }

    // We can iterate over all the Key-Value pairs that are present - O(n)
    for (pair<string, int> item : menu)
    {
        cout << item.first << " - " << item.second << endl;
    }

    return 0;
}
