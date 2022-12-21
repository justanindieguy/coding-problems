#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getAllOccurrences(string s, string searchTerm)
{
    vector<int> indexes;
    int idx = s.find(searchTerm);

    while (idx != -1)
    {
        indexes.push_back(idx);
        idx = s.find(searchTerm, idx + 1);
    }

    return indexes;
}

int main()
{
    string s = "Hello, World! Hello, VS Code! Hello, User! Bye, World!";
    cout << s << endl;

    string searchTerm;
    cout << "Enter search term: ";
    getline(cin, searchTerm);

    vector<int> indexes = getAllOccurrences(s, searchTerm);
    for (int idx : indexes)
    {
        cout << idx << ", ";
    }

    cout << endl;

    return 0;
}
