/*
 * Write a function that takes input an array of distinct integers, and returns
 * the length of highest mountain.
 *
 * - A mountain is defined as adjacent integers that are strictly increasing
 *   until they reach a peak, at which they become strictly decreasing.
 *
 * - At least 3 numbers are required to form a mountain.
 */
#include <iostream>
#include <vector>
using namespace std;

int highestMountain(vector<int> v)
{
    int largest = 0;
    int n = v.size();
    for (int i = 1; i <= n - 2;)
    {
        // Check if v[i] is a peak or not
        if (v[i] > v[i - 1] && v[i] > v[i + 1])
        {
            // The peak is already counted
            int count = 1;
            int j = i;

            // Count backwards (left)
            while (j >= 1 && v[j] > v[j - 1])
            {
                j--;
                count++;
            }

            // Count forwards (right)
            while (i <= n - 2 && v[i] > v[i + 1])
            {
                i++;
                count++;
            }

            largest = max(largest, count);
        }
        else
        {
            i++;
        }
    }

    return largest;
}

int main()
{
    vector<int> v = {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    cout << "Highest Mountain Length: " << highestMountain(v) << endl;
    return 0;
}
