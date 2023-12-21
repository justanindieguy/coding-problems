#include <iostream>

using namespace std;

bool canBePlaced(int matrix[][9], int i, int j, int num, int n)
{
    // Check if given number is already present in row and column
    for (int k = 0; k < n; k++)
    {
        if (matrix[k][j] == num || matrix[i][k] == num)
        {
            return false;
        }
    }

    // Starting indices of sub-grid for i, j
    int subGridStartX = (i / 3) * 3;
    int subGridStartY = (j / 3) * 3;

    for (int x = subGridStartX; x < subGridStartX + 3; x++)
    {
        for (int y = subGridStartY; y < subGridStartY + 3; y++)
        {
            if (matrix[x][y] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int matrix[][9], int i, int j, int n)
{
    // Base case
    if (i == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }

            cout << endl;
        }

        return true;
    }

    // Recursive case

    // Went through every column in the current row, go to next row.
    if (j == n)
    {
        return solveSudoku(matrix, i + 1, 0, n);
    }

    // If the current cell is prefilled, skip it.
    if (matrix[i][j] != 0)
    {
        return solveSudoku(matrix, i, j + 1, n);
    }

    // Cell to be filled.
    for (int num = 1; num <= n; num++)
    {
        if (canBePlaced(matrix, i, j, num, n))
        {
            matrix[i][j] = num;

            if (solveSudoku(matrix, i, j + 1, n))
            {
                return true;
            }
        }
    }

    // Backtracking - none of the digits from 1 to 9 is valid for the given cell
    matrix[i][j] = 0;
    return false;
}

int main()
{
    int n = 9;
    int matrix[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 0},
    };

    if (!solveSudoku(matrix, 0, 0, n))
    {
        cout << "There's no valid solution." << endl;
    }

    return 0;
}
