#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Optimized with Prefix Sum - O(N^2)
vector<int> generatePrefixSum(vector<int> v)
{
    int n = v.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = v[0];
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + v[i];

    return prefixSum;
}

int calculateSubArraySum(vector<int> prefixSum, int i, int j)
{
    return i == 0 ? prefixSum[j] : prefixSum[j] - prefixSum[i - 1];
}

int countSubArraysWithTargetSum(vector<int> v, int targetSum)
{
    int n = v.size();
    vector<int> prefixSum = generatePrefixSum(v);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (calculateSubArraySum(prefixSum, i, j) == targetSum)
                ans++;
        }
    }

    return ans;
}

int countSubArrayWithTargetSumHash(vector<int> v, int target)
{
    int count = 0, currSum = 0;
    unordered_map<int, int> prefixSum;

    for (int num : v)
    {
        currSum += num;

        if (currSum == target)
            count++;

        int diff = currSum - target;
        if (prefixSum.find(diff) != prefixSum.end())
            count += prefixSum[diff];

        prefixSum[currSum]++;
    }

    return count;
}

int main()
{
    int targetSum;
    cin >> targetSum;

    vector<int> v = {3, 4, 7, 2, -3, 1, 4, 2};
    cout << countSubArrayWithTargetSumHash(v, targetSum) << endl;

    return 0;
}
