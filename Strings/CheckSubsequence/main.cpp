/*
 * Given two non-empty strings, write a function that determines whether the
 * second string is subsequence of first one.
 */
#include <iostream>
#include <string>

using namespace std;

bool checkSubsequence(string s1, string s2)
{
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    while (i >= 0 && j >= 0)
    {
        if (s2[j] == s1[i])
        {
            i--;
            j--;
        }
        else
        {
            i--;
        }
    }

    if (j == -1)
        return true;

    return false;
}

int main()
{
    string s1 = "codingminutes";
    string s2 = "gits";
    string result = checkSubsequence(s1, s2) ? "Yes" : "No";
    cout << result << endl;

    return 0;
}
