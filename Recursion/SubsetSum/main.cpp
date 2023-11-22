/*
 * Given a set of non-negative integers, and a value sum, determine the number
 * of subsets of the given set which sum is equals to target sum
 *
 * Input:
 *   arr = [1, 2, 3, 4, 5]
 *   targetSum = 6
 *
 * Output: 3
 */

#include <iostream>
#include <vector>

using namespace std;

int countSubsetsWithTargetSum(vector<int> set, int n, int start, int targetSum)
{
    // Base case
    if (start == n)
    {
        // Sum of all elements in subset is equals to targetSum.
        // We have found a valid subset!
        if (targetSum == 0)
        {
            return 1;
        }

        return 0;
    }

    // Recursive case
    int inc = countSubsetsWithTargetSum(set, n, start + 1, targetSum - set[start]);
    int exc = countSubsetsWithTargetSum(set, n, start + 1, targetSum);
    return inc + exc;
}

int main()
{
    int targetSum = 6;
    vector<int> set = {1, 2, 3, 4, 5};
    cout << countSubsetsWithTargetSum(set, set.size(), 0, targetSum) << endl;

    return 0;
}
