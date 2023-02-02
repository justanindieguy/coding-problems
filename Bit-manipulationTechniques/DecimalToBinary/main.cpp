/*
 * Convert a number from decimal format into binary format.
 *
 * Input
 * N = 10
 *
 * Output
 * 1010
 */
#include <iostream>

using namespace std;

int convertToBinary(int n)
{
    int ans = 0, exp = 1;

    while (n > 0)
    {
        ans += (n % 2) * exp;
        exp *= 10;
        n = n / 2;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << convertToBinary(n) << endl;

    return 0;
}
