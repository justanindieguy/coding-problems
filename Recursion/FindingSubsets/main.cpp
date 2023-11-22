/*
 * Given a string, find all subsets of the given string.
 *
 * Input
 * abc
 *
 * Output
 * "", a, b, c, ab, ac, bc, abc
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getSubsets(vector<string> &subsets, string s, string o, int start, int end)
{
    if (start == end)
    {
        subsets.push_back(o);
        return;
    }

    // Take charater at start
    o += s[start];
    getSubsets(subsets, s, o, start + 1, end);

    // Don't take it
    o.pop_back();
    getSubsets(subsets, s, o, start + 1, end);
}

int main()
{
    vector<string> subsets = {};
    string s = "abc";

    getSubsets(subsets, s, "", 0, s.size());

    for (string s : subsets)
    {
        cout << s << endl;
    }

    return 0;
}
