#include <iostream>

using namespace std;

void isPowerOfTwo(int n)
{
    if ((n & (n - 1)) == 0)
    {
        cout << "Power of two" << endl;
    }
    else
    {
        cout << "Not a power of two" << endl;
    }
}

int main()
{
    int n = 5;
    isPowerOfTwo(n);

    return 0;
}
