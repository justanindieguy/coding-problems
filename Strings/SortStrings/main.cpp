/*
 * Given a list of 'n' strings S0, S1, S2, ..., Sn-1, each consisting of digits
 * and spaces, the number of spaces is the same for each entry, the goal is to
 * implement a variation of a sort command. None of the strings contain
 * consecutive spaces. Also, no string starts with a space nor ends with it.
 * Spaces are used to divide string into columns, which can be used as keys in
 * comparison.
 *
 * The program has to support the required parameters:
 *
 * key: integer denoting the column used as key in comparisons. The left-most
 * column is denoted by 1.
 *
 * reverse: boolean variable indicating whether to reverse the result of
 * comparison.
 *
 * comparison type: either lexicographic or numeric.
 *
 * Lexicographic means that we use the Lexicographical order where for example
 * (122 < 13).
 * Numeric means that we compare the strings by their numerical values, so
 * (13 < 122).
 *
 * If the comparison type is numeric and numeric values of keys Si and Sj are
 * equal for i < j, then Si is considered strictly smaller than Sj because it
 * comes first.
 *
 * Sample Input
 * ------------
 * 3
 * 92 022
 * 82 12
 * 77 13
 * 2 false numeric
 *
 * Sample Output
 * -------------
 * 82 12
 * 77 13
 * 92 022
 *
 * Explanation
 * -----------
 * The key for ordering is 2, reversal is false and ordering is numeric.
 * Therefore, the keys 022, 12 and 13 should be ordered as 12, 13 and 022.
 * Therefore, the final output is 82 12, 77 13 and 92 022.
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int convertToInt(string s)
{
    int ans = 0;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        int digitValue = s[i] - '0';
        int placeValue = pow(10, n - 1 - i);
        ans += digitValue * placeValue;
    }

    return ans;
}

string extractStringAtKey(string str, int key)
{
    char *s = strtok((char *)str.c_str(), " ");
    while (key > 1)
    {
        s = strtok(NULL, " ");
        key--;
    }

    return (string)s;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2)
{
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;

    return convertToInt(key1) < convertToInt(key2);
}

bool lexicoCompare(pair<string, string> s1, pair<string, string> s2)
{
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;

    return key1 < key2;
}

vector<string> getRows()
{
    int totalRows;
    cin >> totalRows;
    cin.get();

    vector<string> rows;
    for (int i = 0; i < totalRows; i++)
    {
        string row;
        getline(cin, row); // Includes white spaces
        rows.push_back(row);
    }

    return rows;
}

vector<pair<string, string>> getRowsWithKeys(int key, vector<string> rows)
{
    vector<pair<string, string>> rowsWithKeys;
    for (string row : rows)
    {
        rowsWithKeys.push_back({row, extractStringAtKey(row, key)});
    }

    return rowsWithKeys;
}

int main()
{
    vector<string> rows = getRows();

    int key;
    string reversal, ordering;
    cin >> key >> reversal >> ordering;

    // 1. Extract keys for comparison and store them
    vector<pair<string, string>> rowsWithKeys = getRowsWithKeys(key, rows);

    // 2. Sorting
    if (ordering == "numeric")
    {
        sort(rowsWithKeys.begin(), rowsWithKeys.end(), numericCompare);
    }
    else
    {
        sort(rowsWithKeys.begin(), rowsWithKeys.end(), lexicoCompare);
    }

    // 3. Reversal
    if (reversal == "true")
    {
        reverse(rowsWithKeys.begin(), rowsWithKeys.end());
    }

    // 4. Output
    for (pair<string, string> p : rowsWithKeys)
    {
        cout << p.first << endl;
    }

    return 0;
}
