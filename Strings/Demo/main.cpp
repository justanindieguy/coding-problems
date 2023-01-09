#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Dynamic array
    string greet = "Hello World!";

    // Traverse over the characters of the string
    for (char ch : greet)
    {
        cout << ch << ",";
    }

    cout << endl;

    // Taking many strings and store them in vector of strings
    string temp;
    vector<string> stringVector;
    int n = 5;
    while (n--)
    {
        getline(cin, temp);
        stringVector.push_back(temp);
    }

    for (string s : stringVector)
    {
        cout << s << ", ";
    }

    cout << endl;
    return 0;
}
