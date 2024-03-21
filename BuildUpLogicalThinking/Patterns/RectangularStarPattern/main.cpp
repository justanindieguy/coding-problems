#include <iostream>

using namespace std;

void printPattern(int n)
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
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
