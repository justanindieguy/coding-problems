/*
 * Given a signed 32-bit integer x, return x with its digits reversed. If
 * reversing x causes the value to go outside the signed 32-bit integer range
 * [-2^31, 2^31 - 1], then return 0.
 *
 * Assume the environment does not allow you to store 64-bit integers (signed or
 * unsigned), then return 0.
 *
 * Example 1:
 *
 *   Input: x = 123
 *   Output: 321
 *
 * Example 2:
 *
 *   Input: x = -123
 *   Output: -321
 *
 * Example 3:
 *
 *   Input: x = 123
 *   Output: 21
 */

#include <iostream>
#include <climits>

using namespace std;

int reverseInteger(int x)
{
    int reversedNumber = 0;
    while (x)
    {
        int lastDigit = x % 10;
        if (reversedNumber > INT_MAX / 10 || reversedNumber < INT_MIN / 10)
        {
            return 0;
        }

        reversedNumber = reversedNumber * 10 + lastDigit;
        x /= 10;
    }

    return reversedNumber;
}

int main()
{
    int x;
    cin >> x;

    cout << reverseInteger(x) << endl;

    return 0;
}
