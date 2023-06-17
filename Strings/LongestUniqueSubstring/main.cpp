#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

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
        leftBound = 0, rightBound,
        maxWindowSize = 0;

    int freqMap[255] = {};

    for (rightBound = 0; rightBound < n; rightBound++)
    {
        char currentChar = s[rightBound];
        freqMap[currentChar]++;

        while (freqMap[currentChar] > 1)
        {
            char leftChar = s[leftBound];
            freqMap[leftChar]--;
            leftBound++;
        }

        int windowSize = (rightBound - leftBound) + 1;
        maxWindowSize = max(maxWindowSize, windowSize);
    }

    return maxWindowSize;
}

int main()
{
    string s = "abcad";
    // string s = "pwwkew";
    // string s = "bbbbb";

    cout << bruteForceApproach(s) << endl;
    cout << linearApproach(s) << endl;

    return 0;
}
