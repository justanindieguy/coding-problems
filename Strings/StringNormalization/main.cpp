/*
 * You are given a sentence with words separated by space.
 * Your task is to:
 *
 * Write a function that returns a copy of this sentence where all the words:
 *   - start with a capital letter
 *   - the rest of the letters are lower case
 *
 * Note:
 *   - Your function should not modify the sentence given as argument.
 *
 * Sample Input:
 *   This is SO MUCH FUN!
 *
 * Sample Output:
 *   This Is So Much Fun!
 *
 */
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

string normalize(string sentence)
{
    string output = sentence;
    output[0] = toupper(output[0]);
    for (int i = 1; sentence[i] != '\0'; i++)
    {
        char curr = sentence[i];
        bool spaceBefore = sentence[i - 1] == ' ';
        if (spaceBefore)
            output[i] = toupper(curr);
        else
            output[i] = tolower(curr);
    }

    return output;
}

int main()
{
    string input;
    getline(cin, input);
    cout << normalize(input) << endl;

    return 0;
}
