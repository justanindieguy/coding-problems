/*
 * Write a function to:
 *   - clear ith bit
 */
#include <iostream>

using namespace std;

void clearIthBit(int &n, int i)
{
    int mask = ~(1 << i);
    n = n & mask;
}

int main()
{
    int i, n = 13;
    cin >> i;

    clearIthBit(n, i);
    cout << "New n value: " << n << endl;

    return 0;
}
