#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool hasUniqueCharacters(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[j] == s[i])
                return false;
        }
    }

    return true;
}

int bruteForceApproach(string s)
{
    int n = s.size(), maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        for (int len = 1; len <= n - i; len++)
        {
            string substr = s.substr(i, len);
            if (hasUniqueCharacters(substr))
            {
                int substrLen = substr.size();
                maxLen = max(maxLen, substrLen);
            }
        }
    }

    return maxLen;
}

int linearApproach(string s)
{
    int n = s.size(),
        leftBound = 0,
        maxLength = 0;

    unordered_map<char, int> charMap = {};

    for (int rightBound = 0; rightBound < n; rightBound++)
    {
        if (charMap.count(s[rightBound]) == 0 || charMap[s[rightBound]] < leftBound)
        {
            charMap[s[rightBound]] = rightBound;
            maxLength = max(maxLength, (rightBound - leftBound) + 1);
        }
        else
        {
            leftBound = charMap[s[rightBound]] + 1;
            charMap[s[rightBound]] = rightBound;
        }
    }

    return maxLength;
}

int setApproach(string s)
{
    int n = s.length(),
        leftBound = 0,
        maxLength = 0;

    unordered_set<char> charSet;

    for (int rightBound = 0; rightBound < n; rightBound++)
    {
        if (charSet.count(s[rightBound]) == 0)
        {
            charSet.insert(s[rightBound]);
            maxLength = max(maxLength, (rightBound - leftBound) + 1);
        }
        else
        {
            while (charSet.count(s[rightBound]))
            {
                charSet.erase(s[leftBound]);
                leftBound++;
            }

            charSet.insert(s[rightBound]);
        }
    }

    return maxLength;
}

int main()
{
    string s = "abcad";
    // string s = "pwwkew";
    // string s = "bbbbb";

    cout << bruteForceApproach(s) << endl;
    cout << linearApproach(s) << endl;
    cout << setApproach(s) << endl;

    return 0;
}
