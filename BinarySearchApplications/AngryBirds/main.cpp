/*
 * There is a long wire along at straight line, which contains N bird nests at
 * positions x1, x2, ..., xN.
 *
 * There are B (B <= N) birds, which become angry towards each other once put
 * into a nest. To put the birds from hurting each other you want to assign
 * birds to nests such that minimum distance between any two birds is as large
 * as possible. What is the largest minimum distance?
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool canPlaceBirds(int birds, int n, vector<int> nests, int separation)
{
    int birdsWithPlace = 1,
        lastLocation = nests[0];

    for (int i = 1; i < n; i++)
    {
        int currentLocation = nests[i];
        if (currentLocation - lastLocation >= separation)
        {
            birdsWithPlace++;
            lastLocation = currentLocation;

            if (birdsWithPlace == birds)
                return true;
        }
    }

    return false;
}

int getMaximumPossibleDistance(int birds, vector<int> nests)
{
    int n = nests.size();

    // Binary Search
    int start = 0,
        end = nests[n - 1] - nests[0],
        ans = -1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        bool canPlace = canPlaceBirds(birds, n, nests, mid);

        if (canPlace)
        {
            ans = mid;
            start = mid + 1;
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
    int birds = 3;
    vector<int> nests = {1, 2, 4, 8, 9};

    // Sorting
    sort(nests.begin(), nests.end());

    cout << getMaximumPossibleDistance(birds, nests) << endl;

    return 0;
}
