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

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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

vector<vector<string>> groupAnagramsSquareTime(vector<string> &strs)
{
    vector<vector<string>> groupedAnagrams{};
    unordered_set<int> groupedIdxs{};

    int n = strs.size();
    if (n == 0)
    {
        return {};
    }

    for (int i = 0; i < n; i++)
    {
        if (groupedIdxs.find(i) != groupedIdxs.end())
        {
            continue;
        }

        vector<string> currentGroup{};
        currentGroup.push_back(strs[i]);
        groupedIdxs.insert(i);

        for (int j = i + 1; j < n; j++)
        {
            if (groupedIdxs.find(j) != groupedIdxs.end())
            {
                continue;
            }

            if (isAnagram(strs[i], strs[j]))
            {
                currentGroup.push_back(strs[j]);
                groupedIdxs.insert(j);
            }
        }

        groupedAnagrams.push_back(currentGroup);
    }

    return groupedAnagrams;
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> groupedAnagrams;

    for (string &s : strs)
    {
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        groupedAnagrams[sorted].push_back(s);
    }

    vector<vector<string>> result{};
    for (auto &it : groupedAnagrams)
    {
        result.push_back(it.second);
    }

    return result;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // vector<vector<string>> groupedAnagrams = groupAnagramsSquareTime(strs);

    vector<vector<string>> groupedAnagrams = groupAnagrams(strs);
    for (vector<string> &group : groupedAnagrams)
    {
        for (string &s : group)
        {
            cout << s << endl;
        }

        cout << "-------------" << endl;
    }
}
