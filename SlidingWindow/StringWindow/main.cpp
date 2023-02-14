/*
 * Given two strings, one big string and one small string, find the 'smallest
 * window' in the big string that contains all characters of the small string.
 *
 * - Window can have additional characters than required.
 *
 * - If small string has duplicates, then those duplicates must be present with
 *   same or higher count in window.
 *
 * Input:
 *   s1 = hello_world
 *   s2 = lol
 *
 * Output:
 *   llo
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

vector<string> getSubstrings(string s)
{
    int n = s.size();
    vector<string> substrings = {};

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            string substring = s.substr(i, j);
            substrings.push_back(substring);
        }
    }

    return substrings;
}

bool hasEveryCharacter(string s1, string s2)
{
    char lastChar = '\0';
    for (char c : s2)
    {
        if (c == lastChar)
            continue;

        lastChar = c;
        int n = count(s2.begin(), s2.end(), c);
        int m = count(s1.begin(), s1.end(), c);

        if (m < n)
            return false;
    }

    return true;
}

string findWindowBruteForce(string s2, vector<string> substrings)
{
    int smallestLen = INT_MAX;
    string smallestSubstring = "";

    for (string substring : substrings)
    {
        int substringLen = substring.size();
        if (hasEveryCharacter(substring, s2) && substringLen < smallestLen)
        {
            smallestLen = substringLen;
            smallestSubstring = substring;
        }
    }

    return smallestSubstring;
}

int main()
{
    string s1;
    cin >> s1;

    string s2;
    cin >> s2;

    vector<string> substrings = getSubstrings(s1);
    cout << findWindowBruteForce(s2, substrings) << endl;

    return 0;
}
