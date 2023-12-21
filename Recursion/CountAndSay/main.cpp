/*
 * The count-and-say sequence is a sequence of digit strings defined by the
 * recursive formula:
 *
 * countAndSay(1) = "1"
 * countAndSay(n) is the way you would "say" the digit string from
 * countAndSay(n - 1), which is then converted into a different string. To
 * determine how you "say" a digit string, split it into the minimal number of
 * substrings such that each substring contains exactly one unique digit. Then
 * for each substring, say the number of digits, then say the digit. Finally,
 * concatenate every said digit.
 */
#include <iostream>
#include <string>

using namespace std;

string countFreq(string &digits)
{
    if (digits.size() == 0)
    {
        return "";
    }

    string result = "";
    char currentDigit = digits[0];
    int count = 1;

    for (int i = 1; digits[i] != '\0'; i++)
    {
        if (digits[i] != currentDigit)
        {
            result += to_string(count);
            result += currentDigit;
            currentDigit = digits[i];
            count = 1;
        }
        else
        {
            count++;
        }
    }

    result += to_string(count);
    result += currentDigit;
    return result;
}

string countAndSay(int n)
{
    if (n == 1)
    {
        return "1";
    }

    string ans = countAndSay(n - 1);
    return countFreq(ans);
}

int main()
{
    cout << "countAndSay(1):" << countAndSay(1) << endl;
    cout << "countAndSay(4):" << countAndSay(4) << endl;

    return 0;
}
