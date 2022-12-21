#include <iostream>
#include <string>

using namespace std;

int main()
{
    string paragraph = "We are learning about STL strings. STL string class is quite powerful.";

    cout << paragraph << endl;

    string word;
    cout << "Enter search term: ";
    getline(cin, word);

    // Find function
    int index = paragraph.find(word);
    if (index != -1)
    {
        cout << "first occ: " << index << endl;
    }

    index = paragraph.find(word, index + 1);
    if (index != -1)
    {
        cout << "second occ: " << index << endl;
    }

    if (index == -1)
    {
        cout << "string not found!" << endl;
    }

    return 0;
}
