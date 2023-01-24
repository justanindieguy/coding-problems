#include <iostream>

using namespace std;

void clearIthBit(int &n, int i)
{
    int mask = ~(1 << i);
    n = (n & mask);
}

void updateIthBit(int &n, int i, int v)
{
    clearIthBit(n, i);

    int mask = (v << i);
    n = n | mask; // Sets the right value
}

int main()
{
    int i, n = 13;
    cin >> i;

    updateIthBit(n, i, 0);
    cout << n << endl;

    return 0;
}
