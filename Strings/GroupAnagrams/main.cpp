/*
 * Given an array of string strs, group the anagrams together. You can return
 * the answer in any order.
 *
 * Example 1:
 *   Input:
 *     strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 *   Output:
 *     [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]
 *
 * Example 2:
 *   Input:
 *     strs = [""]
 *   Output:
 *     [[""]]
 *
 * Example 3:
 *   Input:
 *     strs = ["a"]
 *   Output:
 *     [["a"]]
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isAnagram(string s1, string s2)
{
    unordered_map<char, int> chars{};

    for (char c : s1)
    {
        chars[c]++;
    }

    for (char c : s2)
    {
        if (chars.find(c) != chars.end())
        {
            chars[c]--;
        }
        else
        {
            return false;
        }
    }

    for (auto &it : chars)
    {
        if (it.second > 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s1;
    cin >> s1;

    string s2;
    cin >> s2;

    if (isAnagram(s1, s2))
    {
        cout << "Anagram" << endl;
    }
    else
    {
        cout << "Not Anagram" << endl;
    }

    return 0;
}
