/*
 * Given an integer N and an integer P, you need to find the square root of
 * number N upto P places. Do it without using a library function.
 *
 * Input:
 *
 * N = 10
 * P = 3
 *
 * Output: 3.162
 */

#include <iostream>

using namespace std;

float squareRoot(int n, int p)
{
    int start = 0, end = n;
    float ans = 0;

    // Binary Search (Search Space 0...N)
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid <= n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    // Linear Search for each place (floating part)
    float increment = 0.1;
    for (int place = 1; place <= p; place++)
    {
        // Do linear search
        while (ans * ans <= n)
        {
            ans += increment;
        }

        ans -= increment;
        increment /= 10.0;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    int p;
    cin >> p;

    cout << squareRoot(n, p) << endl;

    return 0;
}
