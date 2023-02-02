/*
 * The planet earth is under a threat from the aliens of the outer space and
 * your task is to defeat an enemy who is N steps above you (assume yourself to
 * be at the ground level i.e. at the 0th level). You can take jumps in power of
 * 2. In order to defeat the enemy as quickly as possible you have to reach the
 * Nth step in minimum moves possible.
 *
 * Input Format:
 *
 * In the function an integer is passed.
 *
 * Output Format:
 *
 * Return an integer representing minimum jumps.
 */
#include <iostream>
#include <cmath>

using namespace std;

int earthLevel(int n)
{
    int m = 1, lvl = 0;
    while (m < n)
    {
        m = m << 1;
        lvl++;
    }

    return lvl;
}

int earthLevelLog(int n)
{
    return ceil(log2(n));
}

int main()
{
    int n;
    cin >> n;

    cout << earthLevel(n) << endl;
    cout << earthLevelLog(n) << endl;

    return 0;
}
