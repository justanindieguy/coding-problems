/*
 * Write a function to:
 *   - get ith bit
 */
#include <iostream>

using namespace std;

int getIthBit(int n, int i)
{
    int mask = 1 << i;
    return (n & mask) > 0 ? 1 : 0;
}

int main()
{
    int i, n = 5;
    cin >> i;

    cout << "Bit at " << i << "th position: " << getIthBit(n, i) << endl;

    return 0;
}
