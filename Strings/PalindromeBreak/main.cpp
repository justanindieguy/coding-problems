/*
 * Given a palindromic string of lowercase English letters palindrome, replace
 * exactly one character with any lowercase English letter so that the resulting
 * string is NOT a palindrome and that it is the lexicographically smallest one
 * possible.
 *
 * Return the resulting string. If there is no way to replace a character to
 * make it not a palindrome return an empty string.
 *
 * Example 1:
 *   Input: palindrome = "abccba"
 *   Output: "aaccba"
 *   Explanation: There are many ways to make "abccba" not a palindrome, such as
 *   "zbccba", "aaccba", "abacba".
 *   Of all the ways, "aaccba" is the lexicographically smallest.
 *
 * Example 2:
 *   Input: palindrome = "a"
 *   Output: ""
 *   Explanation: There is no way to replace a single character to make "a" not
 *   a palindrome, so return empty string.
 *
 * Example 3:
 *   Input: palindrome = "aa"
 *   Output: "ab"
 *
 * Example 4:
 *   Input: palindrome = "aba"
 *   Output: "abb"
 */
#include <iostream>
#include <string>

using namespace std;

string breakPalindrome(string palindrome)
{
    int n = palindrome.size();
    if (n <= 1)
        return "";

    bool isOdd = n % 2 != 0;
    int midIdx = n / 2;

    for (int i = 0; palindrome[i] != '\0'; i++)
    {
        if (isOdd && i == midIdx)
        {
            continue;
        }
        if (palindrome[i] != 'a')
        {
            palindrome[i] = 'a';
            break;
        }
        if (i == n - 1)
        {
            palindrome[i] = 'b';
            break;
        }
    }

    return palindrome;
}

int main()
{
    string palindrome;
    getline(cin, palindrome);
    cout << breakPalindrome(palindrome) << endl;

    return 0;
}
