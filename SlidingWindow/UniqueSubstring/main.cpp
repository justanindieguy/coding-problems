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
#include <unordered_map>

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

// Sliding Window Approach - O(N)
string getLargestUniqueSubstringSw(string s)
{
    int i = 0, j = 0;
    int startWindow = -1, windowLength = 0, maxWindowLength = 0;
    unordered_map<char, int> m = {};

    while (j < s.size())
    {
        char ch = s[j];

        // Check if it is inside hashmap and is in the current window.
        if (m.count(ch) != 0 && m[ch] >= i)
        {
            i = m[ch] + 1;
            windowLength = j - i; // Updated remaining window length excluding current char.
        }

        // Update the last occurrence.
        m[ch] = j;
        windowLength++;
        j++;

        // Update maxWindowLength at every step.
        if (windowLength > maxWindowLength)
        {
            maxWindowLength = windowLength;
            startWindow = i;
        }
    }

    return s.substr(startWindow, maxWindowLength);
}

int main()
{
    string s;
    cin >> s;

    cout << getLargestUniqueSubstringSw(s) << endl;

    return 0;
}
