#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> KEYPAD = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void printKeypadOutput(string input, string output, int i = 0)
{
    // Base case
    if (input[i] == '\0')
    {
        cout << output << endl;
        return;
    }

    // Recursive case
    int currentDigit = input[i] - '0';
    if (currentDigit == 0 || currentDigit == 1)
    {
        printKeypadOutput(input, output, i + 1);
    }

    // Keypad
    string digitChars = KEYPAD[currentDigit];
    for (char c : digitChars)
    {
        printKeypadOutput(input, output + c, i + 1);
    }

    return;
}

int main()
{
    string input;
    cin >> input;

    string output = "";
    printKeypadOutput(input, output);

    return 0;
}
