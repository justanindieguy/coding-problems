/*
 * Given a string, write a function to find the largest substring with unique
 * characters (no duplicates).
 *
 * Sample Input
 *   prateekbhaiya
 *   aabcb
 *
 * Sample Output
 *   ekbhaiy
 *   abc
 */
#include <iostream>
#include <set>
#include <string>

using namespace std;

bool hasUniqueCharacters(string s)
{
    bool isUnique = true;
    set<char> checkedChars = {};

    for (char c : s)
    {
        if (checkedChars.find(c) != checkedChars.end())
            return false;

        checkedChars.insert(c);
    }

    return true;
}

string getLargestUniqueSubstring(string s)
{
    int n = s.size();
    string largestSubstring = "";

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            string substring = string(s, i, (j + 1) - i);
            bool isLarger = substring.size() > largestSubstring.size();

            if (hasUniqueCharacters(substring) && isLarger)
                largestSubstring = substring;
        }
    }

    return largestSubstring;
}

int main()
{
    string s;
    cin >> s;

    cout << getLargestUniqueSubstring(s) << endl;

    return 0;
}
