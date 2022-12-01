// Given an array of integers print all pairs whose sum is equal to k.
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Brute force - O(n^2)
void pairSumBruteForce(vector<int> &v, int k)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = v.size() - 1; j > i; j--)
        {
            int sum = v[i] + v[j];
            if (sum == k)
                cout << v[i] << ", " << v[j] << endl;
        }
    }
}

// Sorting - O(n Log n)
void pairSumSorting(vector<int> v, int k)
{
    sort(v.begin(), v.end());

    int i = 0;
    int j = v.size() - 1;
    while (i < j)
    {
        int sum = v[i] + v[j];
        if (sum == k)
        {
            cout << v[i] << ", " << v[j] << endl;
            i++;
            j--;
        }
        else if (sum < k)
            i++;
        else
            j--;
    }
}

// Sorting + Binary search - O(n Log n)
void pairSumSortingBinarySearch(vector<int> v, int k)
{
    sort(v.begin(), v.end());

    unordered_set<int> alreadyPaired; // used to not print repeated pairs
    for (int i = 0; i < v.size(); i++)
    {
        if (alreadyPaired.find(v[i]) != alreadyPaired.end())
            continue;

        int diff = k - v[i];
        if (binary_search(v.begin(), v.end(), diff))
        {
            cout << v[i] << ", " << diff << endl;
            alreadyPaired.insert(diff);
        }
    }
}

// MOST EFFICIENT!!!
// Unordered_set - O(n)
void pairSumSet(vector<int> v, int k)
{
    unordered_set<int> s;

    for (int i = 0; i < v.size(); i++)
    {
        int diff = k - v[i];
        if (s.find(diff) != s.end())
            cout << v[i] << ", " << diff << endl;

        s.insert(v[i]);
    }
}

int main()
{
    int targetSum = 8;
    vector<int> v = {2, 1, 8, 6, -2, 5, 3, 0};

    cout << "Pair sum - (Brute force):" << endl;
    pairSumBruteForce(v, targetSum);

    cout << "Pair sum - (Sorting):" << endl;
    pairSumSorting(v, targetSum);

    cout << "Pair sum - (Sorting + Binary search):" << endl;
    pairSumSortingBinarySearch(v, targetSum);

    cout << "Pair sum - (Sets):" << endl;
    pairSumSet(v, targetSum);

    return 0;
}
