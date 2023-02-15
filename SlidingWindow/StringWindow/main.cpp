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

string findWindowSlidingWindow(string str, string pattern)
{
    // Array as Frequency Map (unordered_map can be used too).
    int freqPattern[256] = {0};
    int freqString[256] = {0};

    for (int i = 0; i < pattern.size(); i++)
    {
        freqPattern[pattern[i]]++;
    }

    // Sliding Window Algorithm
    int cnt = 0;
    int start = 0;     // Left contracting
    int startIdx = -1; // Start Index for best window
    int minSoFar = INT_MAX;
    int windowSize = 0;

    for (int i = 0; i < str.size(); i++)
    {
        // Expand the window by including current character.
        char ch = str[i];
        freqString[ch]++;

        // Count how many characters have been matched 'till now (string and pattern).
        if (freqPattern[ch] != 0 && freqString[ch] <= freqPattern[ch])
        {
            cnt++;
        }

        // If all characters of the pattern are found in the current window then you can start contracting.
        if (cnt == pattern.size())
        {
            // Start contracting from the left to remove unwanted characters
            while (freqPattern[str[start]] == 0 || freqString[str[start]] > freqPattern[str[start]])
            {
                freqString[str[start]]--;
                start++;
            }

            windowSize = i - start + 1;
            if (windowSize < minSoFar)
            {
                minSoFar = windowSize;
                startIdx = start;
            }
        }
    }

    if (startIdx == -1)
    {
        return "No window found!";
    }

    return str.substr(startIdx, minSoFar);
}

int main()
{
    string s1;
    cin >> s1;

    string s2;
    cin >> s2;

    // vector<string> substrings = getSubstrings(s1);
    cout << findWindowSlidingWindow(s1, s2) << endl;

    return 0;
}
