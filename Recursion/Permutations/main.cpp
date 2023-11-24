/*
 * Given a string s, find all permutations of the string.
 *
 * Input:
 *   abc
 *
 * Output:
 *   abc, acb, bac, bca, cab, cba
 */

#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

void getPermutations(vector<string> &o, string s, int i)
{
    if (s[i] == '\0')
    {
        o.push_back(s);
        return;
    }

    for (int j = i; s[j] != '\0'; j++)
    {
        swap(s[i], s[j]);
        getPermutations(o, s, i + 1);
        swap(s[i], s[j]);
    }
}

vector<string> getSortedPermutations(string s)
{
    vector<string> permutations;
    getPermutations(permutations, s, 0);

    set<string> st(permutations.begin(), permutations.end());

    permutations.clear();
    copy(st.begin(), st.end(), back_inserter(permutations));

    return permutations;
}

int main()
{
    string s;
    cin >> s;

    for (string p : getSortedPermutations(s))
    {
        cout << p << endl;
    }

    return 0;
}
