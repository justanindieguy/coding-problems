/*
 * Given a string, write a function to replace all spaces in a string with '%20'.
 * It is given that the string has sufficient space at the end to hold the
 * additional characters.
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string REPLACE_WITH = "%20";

vector<int> getAllOccurrences(string s, string term)
{
    vector<int> indexes;
    int idx = s.find(term);
    while (idx != -1)
    {
        indexes.push_back(idx);
        idx = s.find(term, idx + 1);
    }

    return indexes;
}

int getAdditionalLen(string s)
{
    vector<int> occurrences = getAllOccurrences(s, " ");
    return occurrences.size() * (REPLACE_WITH.size() - 1);
}

string resizeString(string s)
{
    int additionalLen = getAdditionalLen(s);
    s.resize(s.size() + additionalLen);

    return s;
}

string space20Quadratic(string s)
{
    int stringLen = s.size();
    s = resizeString(s);

    int diff = REPLACE_WITH.size() - 1;
    for (int i = 0; i < stringLen;)
    {
        if (s[i] == ' ')
        {
            int j;
            for (j = stringLen - 1; j > i; j--)
            {
                s[j + diff] = s[j];
            }

            for (j = 0; j < REPLACE_WITH.size(); j++)
            {
                s[i] = REPLACE_WITH[j];
                i++;
            }

            stringLen += diff;
        }
        else
        {
            i++;
        }
    }

    return s;
}

string space20Linear(string s)
{
    int stringLen = s.size();
    int additionalLen = getAdditionalLen(s);

    s = resizeString(s);
    int diff = REPLACE_WITH.size() - 1;
    for (int i = stringLen - 1; i >= 0; i--)
    {
        int moveTo = i + additionalLen;
        if (s[i] == ' ')
        {
            int stop = moveTo - diff;
            int j = moveTo;
            while (j >= stop)
            {
                s[j] = REPLACE_WITH[j - stop];
                j--;
            }

            additionalLen -= diff;
        }
        else
        {
            s[moveTo] = s[i];
        }
    }

    return s;
}

int main()
{
    string s = "hello world,  how are you?";
    cout << s << endl;
    cout << space20Quadratic(s) << endl;
    cout << space20Linear(s) << endl;

    return 0;
}
