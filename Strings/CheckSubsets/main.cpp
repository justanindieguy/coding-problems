/*
 * Given two non-empty strings, write a function that determines whether the
 * second string is subset of first one.
 */
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool isSubsetBruteForce(string s1, string s2)
{
    if (s2.size() == 0)
        return true;

    for (char c1 : s2)
    {
        bool present = false;
        for (char c2 : s1)
        {
            if (c1 == c2)
            {
                present = true;
                break;
            }
        }

        if (!present)
            return false;
    }

    return true;
}

bool isSubset(string s1, string s2)
{
    if (s2.size() == 0)
        return true;

    unordered_set<char> chars(s1.begin(), s1.end());
    for (char c : s2)
    {
        if (chars.find(c) == chars.end())
            return false;
    }

    return true;
}

int main()
{
    string s1 = "codingminutes";
    string s2 = "cines";
    string result = isSubset(s1, s2) ? "Yes" : "No";
    cout << result << endl;

    return 0;
}
