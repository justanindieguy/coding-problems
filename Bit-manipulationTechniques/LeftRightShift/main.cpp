#include <iostream>

using namespace std;

int main()
{
    int num = 10;

    // a * b^2
    cout << "Left Shift Operator: " << (num << 2) << endl;

    // a / b^2
    cout << "Right Shift Operator: " << (num >> 2) << endl;

    return 0;
}
