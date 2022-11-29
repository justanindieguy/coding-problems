#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> menu;

    // Inser Key-Value pairs inside the HashTable - O(1) Operation
    menu["taco"] = 15;
    menu["colddrink"] = 20;
    menu["pozole"] = 59;
    menu["pizza"] = 89;
    menu["hamburger"] = 49;
    menu["birria"] = 99;

    // Update query - O(1)
    menu["pozole"] = (1 + 0.1) * menu["pozole"];

    // Deletion - O(1)
    menu.erase("pozole");

    // Searching inside a collection of Key-Value pairs (stored inside a HashTable)
    // O(1)
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
