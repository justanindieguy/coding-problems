#include <iostream>

using namespace std;

void printBoard(int n, int board[][20])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }
}

bool canPlace(int board[][20], int n, int x, int y)
{
    // Column
    for (int k = 0; k < x; k++)
    {
        if (board[k][y] == 1)
        {
            return false;
        }
    }

    // Left Diagonal
    int i = x, j = y;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }

        i--;
        j--;
    }

    // Right diagonal
    i = x, j = y;
    while (i >= 0 && j < n)
    {
        if (board[i][j] == 1)
        {
            return false;
        }

        i--;
        j++;
    }

    return true;
}

bool solveNQueen(int n, int board[][20], int i)
{
    // Base case
    if (i == n)
    {
        // Print the board
        printBoard(n, board);

        return true;
    }

    // Recursive case
    // Try to place a queen in every row
    for (int j = 0; j < n; j++)
    {
        // Check whether the current i, j position is safe or not
        if (canPlace(board, n, i, j))
        {
            board[i][j] = 1; // Put
            bool success = solveNQueen(n, board, i + 1);

            if (success)
            {
                return true;
            }

            // Backtrack
            board[i][j] = 0; // Remove
        }
    }

    // There is no valid position for a queen in the current row
    return false;
}

int main()
{
    int board[20][20] = {0};

    int n;
    cin >> n;

    solveNQueen(n, board, 0);

    return 0;
}
