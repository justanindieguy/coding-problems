/*
 * You are given a string, you need to print all subsequences of the string
 * sorted by length and lexicographic sorted order if length is same.
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    if (n == m)
    {
        return s1 < s2;
    }

    return n < m;
}

void generateSubsequences(string s, string output, vector<string> &subsequences)
{
    // Base Case
    if (s.size() == 0)
    {
        subsequences.push_back(output);
        return;
    }

    // Recursive Case
    char ch = s[0];
    string reducedInput = s.substr(1);

    // Take
    generateSubsequences(reducedInput, output + ch, subsequences);

    // Do not take
    generateSubsequences(reducedInput, output, subsequences);
}

int main()
{
    string s;
    cin >> s;
    vector<string> subsequences;

    generateSubsequences(s, "", subsequences);
    sort(subsequences.begin(), subsequences.end(), compare);

    for (string sub : subsequences)
    {
        cout << sub << endl;
    }

    return 0;
}
