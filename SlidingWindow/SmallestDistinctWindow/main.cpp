#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string getSmallestDistinctWindow(string s)
{
    unordered_set<char> chars(s.begin(), s.end());
    int uniqueChars = chars.size();
    int freqString[256] = {0};

    int matches = 0;
    int start = 0, startIdx = -1;
    int smallestWindowLength = INT_MAX;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (freqString[ch] == 0)
            matches++;

        freqString[ch]++;

        if (matches == uniqueChars)
        {
            while (matches == uniqueChars)
            {
                freqString[s[start]]--;

                if (freqString[s[start]] == 0)
                    matches--;

                start++;
            }

            int windowStart = start - 1;
            int windowLength = i - windowStart + 1;
            if (windowLength < smallestWindowLength)
            {
                startIdx = windowStart;
                smallestWindowLength = windowLength;
            }
        }
    }

    if (startIdx == -1)
        return "Window not found!";

    return s.substr(startIdx, smallestWindowLength);
}

int main()
{
    string s = "aabcbcdbcaaad";
    cout << getSmallestDistinctWindow(s) << endl;

    return 0;
}
