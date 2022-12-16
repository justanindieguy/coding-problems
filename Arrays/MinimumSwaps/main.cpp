/*
 * Given an array of size N, find the minimum number of swaps needed to make
 * the array as sorted.
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int countMinSwaps(vector<int> arr)
{
    int ans = 0;
    int n = arr.size();

    // Store the current indices.
    pair<int, int> valuesAndOldIndexes[n];
    for (int i = 0; i < n; i++)
    {
        valuesAndOldIndexes[i].first = arr[i];
        valuesAndOldIndexes[i].second = i;
    }

    // Know the actual positions of elements (sorting).
    sort(valuesAndOldIndexes, valuesAndOldIndexes + n);

    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        // If element is visited or element is in the right position.
        int oldPosition = valuesAndOldIndexes[i].second;
        if (visited[i] == true || oldPosition == i)
            continue;

        // Visiting the element (index) for the first time.
        int node = i;
        int cycleLength = 0;
        while (!visited[node])
        {
            visited[node] = true;
            int nextNode = valuesAndOldIndexes[node].second;
            node = nextNode;
            cycleLength++;
        }

        ans += (cycleLength - 1);
    }

    return ans;
}

int main()
{
    vector<int> arr{10, 11, 5, 4, 3, 2, 1};
    cout << "Minimum Swaps: " << countMinSwaps(arr) << endl;
    return 0;
}
