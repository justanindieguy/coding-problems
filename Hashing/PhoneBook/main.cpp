#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;

int main()
{
    map<string, list<string>> phonebook;

    // Single Key
    phonebook["Emmanuel"].push_back("+525573946402");
    phonebook["Emmanuel"].push_back("+525521383203");
    phonebook["Emmanuel"].push_back("+525489023453");

    // Single Key - Total: 2 keys
    phonebook["Tony"].push_back("+018690852340");
    phonebook["Tony"].push_back("+019823452834");
    phonebook["Tony"].push_back("+017590890234");

    // Single Key - Total: 3 keys
    phonebook["Ana"].push_back("+448934512320");
    phonebook["Ana"].push_back("+444342390343");
    phonebook["Ana"].push_back("+445590823222");

    for (pair<string, list<string>> entry : phonebook)
    {
        string personName = entry.first;
        cout << personName << ":" << endl;

        list<string> phoneNumbers = entry.second;
        for (string phoneNumber : phoneNumbers)
        {
            cout << "\t" << phoneNumber << endl;
        }
    }

    return 0;
}
