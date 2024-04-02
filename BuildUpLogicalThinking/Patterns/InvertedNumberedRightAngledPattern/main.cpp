#include <iostream>

using namespace std;

void printPattern(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }

        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    printPattern(n);

    return 0;
}
