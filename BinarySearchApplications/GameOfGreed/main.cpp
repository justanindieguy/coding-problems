/*
 * You are playing a game with you 'k' friends. You have an array of N coins,
 * at each index i you have a coin of value a[i].
 * Your task is to divide the coins, among a group of K friends by doing
 * consecutive segments (k-subarrays) of the array.
 * Each friend will get a total sum of the coins in that subarray. Since all
 * your fiends are greedy, and the will pick the largest k - 1 segments and you
 * will get the smallest segment. Find out the maximum value you can make by
 * making an optimal partition.
 *
 * Note: The coins may or may not be sorted!
 *
 * Input:
 *   K = 3;
 *   coins = {1, 2, 3, 4};
 *
 * Output: 3
 *
 * Explanation:
 *   The ideal partition looks like this:
 *     [1 + 2] = 3
 *     [3] = 3
 *     [4] = 4
 *   You will get a maximum of 3 coins in the best case.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool divideAmongK(vector<int> v, int n, int k, int minCoins)
{
    int friendsCovered = 0,
        currentFriend = 0;

    for (int i = 0; i < n; i++)
    {
        if (currentFriend + v[i] >= minCoins)
        {
            friendsCovered += 1;
            currentFriend = 0;
        }
        else
        {
            currentFriend += v[i];
        }
    }

    return friendsCovered >= k;
}

int binarySearchApproach(vector<int> v, int k)
{
    int n = v.size(),
        startIdx = distance(v.begin(), min_element(v.begin(), v.end())),
        start = v[startIdx],
        end = 0;

    for (int num : v)
    {
        end += num;
    }

    int ans = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        bool isPossible = divideAmongK(v, n, k, mid);

        if (isPossible)
        {
            start = mid + 1;
            ans = mid;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> coins = {10, 22, 40, 50};
    int k = 3;

    cout << binarySearchApproach(coins, k) << endl;

    return 0;
}
