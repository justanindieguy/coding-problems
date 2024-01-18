/*
 * Given an array "nums" of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 *
 * Example 1:
 *
 *   Input:
 *   nums = [1, 2, 3]
 *
 *   Output:
 *   [[1, 2, 3], [2, 1, 3], [2, 3, 1] [3, 1, 2], [3, 2, 1]]
 *
 * Example 2:
 *
 *   Input:
 *   nums = [0, 1]
 *
 *   Output:
 *   [[0, 1], [1, 0]]
 *
 * Example 3:
 *
 *   Input:
 *   nums = [1]
 *
 *   Output:
 *   [1]
 *
 */

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> v)
{
    for (int i = 0, n = v.size(); i < n; i++)
    {
        if (i == n - 1)
        {
            cout << v[i];
        }
        else
        {
            cout << v[i] << ", ";
        }
    }

    cout << endl;
}

void permute(vector<int> &nums, vector<vector<int>> &permutations, int k)
{
    static int n = nums.size();
    static vector<bool> available(n, true); // Keeps track of elements already in currentPermutation
    static vector<int> currentPermutation(n, 0);

    if (k == n)
    {
        permutations.push_back(currentPermutation);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (available[i])
        {
            currentPermutation[k] = nums[i];
            available[i] = false;
            permute(nums, permutations, k + 1);
            available[i] = true;
        }
    }
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = {};
    permute(nums, permutations, 0);

    for (vector<int> permutation : permutations)
    {
        printVector(permutation);
    }

    return 0;
}
