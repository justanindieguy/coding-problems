/*
 * Given a string s, sort it in decreasing order based on the frequency of the
 * characters. The frequency of a character is the number of times it appears in
 * the string.
 *
 * Return the sorted string. If there are multiple answer, return any of them.
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct Comparator
{
    Comparator(unordered_map<char, int> freqMap) { this->freqMap = freqMap; }

    bool operator()(int a, int b)
    {
        if (freqMap[a] == freqMap[b])
        {
            return a < b;
        }

        return this->freqMap[a] > this->freqMap[b];
    }

    unordered_map<char, int> freqMap;
};

// Uses frequency map and then sorts the string based on that map.
string frequencySort(string &s)
{
    unordered_map<char, int> freqMap = {};

    for (char c : s)
    {
        freqMap[c]++;
    }

    sort(s.begin(), s.end(), Comparator(freqMap));
    return s;
}

/**
 * Creates a frequency map, then sorts it in decrease order such that each
 * element in the sorted frequency map is a pair with the count and the
 * character associated with it.
 *
 * After that, traverses the sorted count in decrease order and appends to a new
 * string the same character n times until no one is left.
 */
string frequencySortTwo(string s)
{
    vector<int> freqMap(128, 0);

    for (char c : s)
    {
        freqMap[c]++;
    }

    vector<pair<int, char>> sortedCount;
    sortedCount.reserve(128);

    for (int i = 0; i < freqMap.size(); i++)
    {
        if (freqMap[i] > 0)
        {
            sortedCount.push_back({freqMap[i], i});
        }
    }

    sort(sortedCount.begin(), sortedCount.end(), [](auto &a, auto &b)
         { return a.first > b.first; });

    string ans;
    ans.reserve(s.size());

    for (auto [count, c] : sortedCount)
    {
        ans += string(count, c);
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;

    string ans = frequencySortTwo(s);

    cout << ans << endl;

    return 0;
}
