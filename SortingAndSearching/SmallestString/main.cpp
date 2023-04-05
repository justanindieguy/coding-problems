/*
 * You're given a list of n strings a1, a2, ..., an. You'd like to concatenate
 * them together in some order such that the resulting string would be
 * lexicographically smallest.
 *
 * Given the list of strings, output the lexicographically smallest
 * concatenation.
 *
 * Input
 * 3
 * c
 * cb
 * cba
 *
 * Output: cbacbc
 * --------------------
 *
 * Input
 * 3
 * a
 * ab
 * aba
 *
 * Output: aabaab
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void merge(vector<string> &strings, int start, int end)
{
    int mid = (start + end) / 2;

    vector<string> temp;
    int i = start, j = mid + 1;
    while (i <= mid && j <= end)
    {
        string x = strings[i] + strings[j];
        string y = strings[j] + strings[i];

        if (x < y)
        {
            temp.push_back(strings[i]);
            i++;
        }
        else
        {
            temp.push_back(strings[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(strings[i]);
        i++;
    }

    while (j <= end)
    {
        temp.push_back(strings[j]);
        j++;
    }

    int k = 0;
    for (int idx = start; idx <= end; idx++)
    {
        strings[idx] = temp[k];
        k++;
    }
}

void mergeSort(vector<string> &strings, int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    mergeSort(strings, start, mid);
    mergeSort(strings, mid + 1, end);

    merge(strings, start, end);
}

int main()
{
    vector<string> strings{"a", "ab", "aba"};

    int n = strings.size();
    mergeSort(strings, 0, n - 1);

    for (string s : strings)
    {
        cout << s;
    }

    cout << endl;

    return 0;
}
