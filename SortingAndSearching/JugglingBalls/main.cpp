/*
 * Given an array containing balls of Red, Blue and Green Color in a random
 * order. Your goal is to arrange these balls in sorted order - Red balls,
 * followed by Blue and then Green balls. Red balls are denoted using number 0,
 * Blue using 1 and Green using 2.
 *
 * Note: Try to solve the problem in a single scan of the array without using
 * extra space.
 *
 * Input:
 * {0, 0, 1, 2, 0, 1, 2, 0}
 *
 * Output:
 * {0, 0, 0, 0, 1, 1, 2, 2}
 */

#include <iostream>
#include <vector>

using namespace std;

void sortBalls(vector<int> &balls)
{
    // Sort the balls in place in a single time - O(N) time, O(1) space

    int n = balls.size(),
        low = 0,
        mid = 0,
        high = n - 1;

    while (mid <= high)
    {
        if (balls[mid] == 0)
            swap(balls[low++], balls[mid++]);
        else if (balls[mid] == 1)
            mid++;
        else
            swap(balls[mid], balls[high--]);
    }
}

int main()
{
    vector<int> balls = {0, 0, 1, 2, 0, 1, 2, 0};

    sortBalls(balls);
    for (int ball : balls)
    {
        cout << ball << ", ";
    }

    cout << endl;

    return 0;
}
