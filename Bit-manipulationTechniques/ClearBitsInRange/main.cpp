#include <iostream>

using namespace std;

void clearBitsInRange(int &n, int i, int j)
{
    int a = -1 << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    n = n & mask;
}

int main()
{
    int n = 31, i = 1, j = 3;

    clearBitsInRange(n, i, j);
    cout << n << endl;

    return 0;
}
