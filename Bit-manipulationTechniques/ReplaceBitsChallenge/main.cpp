/*
 * Replace bits in N by M
 * You are given two 32-bit numbers, N and M, and two bit positions i and j.
 * Write a method to set all bits between i and j in N equal to M.
 * M (becomes a substring of N located at and starting at j)
 */
#include <iostream>

using namespace std;

void clearBitsInRange(int &n, int i, int j)
{
    int a = (-1) << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    n = n & mask;
}

void replaceBitsInRange(int &n, int m, int i, int j)
{
    clearBitsInRange(n, i, j);
    int mask = m << i;
    n = n | mask;
}

int main()
{
    int n = 512, m = 21, i = 2, j = 6;

    replaceBitsInRange(n, m, i, j);
    cout << n << endl;

    return 0;
}
