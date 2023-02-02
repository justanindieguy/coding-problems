/*
 * Write a function to:
 *   - clear the last i bits
 */
#include <iostream>

using namespace std;

void clearLastIBits(int &n, int i)
{
    int mask = -1 << i;
    n = n & mask;
}

int main()
{
    int i, n = 15;
    cin >> i;

    clearLastIBits(n, i);
    cout << n << endl;

    return 0;
}
