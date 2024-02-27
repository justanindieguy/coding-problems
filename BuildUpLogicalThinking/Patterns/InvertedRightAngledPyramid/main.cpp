#include <iostream>

using namespace std;

void printPattern(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
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
