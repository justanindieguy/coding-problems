/*
 * Given an array containing N integers, and a number S denoting a target sum.
 *
 * Find all distinct integers that can add up to form target sum.
 * The numbers in each triplet should be ordered in ascending order,
 * and triplets should be ordered too.
 *
 * Return empty array if no such triplet exists.
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void printTriplets(vector<vector<int>> v)
{
    for (vector<int> triplet : v)
    {
        for (int num : triplet)
            cout << num << ", ";

        cout << endl;
    }
}

// Brute Force - O(N^3)
vector<vector<int>> tripletsBruteForce(vector<int> v, int s)
{
    int n = v.size();
    vector<vector<int>> triplets;

    if (n < 3)
        return triplets;

    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (v[i] + v[j] + v[k] == s)
                    triplets.push_back({v[i], v[j], v[k]});
            }
        }
    }

    return triplets;
}

// Two Pointer Approach - O(N^2)
vector<vector<int>> triplets(vector<int> v, int s)
{
    int n = v.size();
    vector<vector<int>> triplets;

    if (n < 3)
        return triplets;

    // Pick every v[i], solve pair sum for remaining part.
    sort(v.begin(), v.end());
    for (int i = 0; i <= n - 3; i++)
    {
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = v[i] + v[j] + v[k];

            if (sum == s)
            {
                triplets.push_back({v[i], v[j], v[k]});
                j++;
                k--;
            }
            else if (sum < s)
                j++;
            else
                k--;
        }
    }

    return triplets;
}

int main()
{
    int targetSum = 18;
    vector<int> v = {15, 2, 3, 5, 4, 6, 7, 8, 9, 1};

    cout << "Triplets - Brute Force:" << endl;
    printTriplets(tripletsBruteForce(v, targetSum));

    cout << "Triplets:" << endl;
    printTriplets(triplets(v, targetSum));

    return 0;
}
