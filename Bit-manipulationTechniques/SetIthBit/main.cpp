/*
 * Write a function to:
 *   - set ith bit
 */
#include <iostream>

using namespace std;

void setIthBit(int &n, int i)
{
    int mask = (1 << i);
    n = (n | mask);
}

int main()
{
    int i, n = 5;
    cin >> i;

    setIthBit(n, i);
    cout << "New value of n: " << n << endl;

    return 0;
}
