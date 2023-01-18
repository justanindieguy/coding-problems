#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;

    /* x & 1 will find out the last bit
     * if last bit is 1 "x & 1" will return ...0001
     * if last bit is 0 "x & 1" will return ...0000
     */
    if (x & 1)
        cout << "Odd" << endl;
    else
        cout << "Even" << endl;

    return 0;
}
