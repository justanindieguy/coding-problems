#include <iostream>

using namespace std;

void printPattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
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
