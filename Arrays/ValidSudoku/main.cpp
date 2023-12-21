#include <iostream>
#include <unordered_set>

using namespace std;

bool isValid(char board[][9], int row, int col)
{
    for (int i = 0; i < 9; i++)
    {
        if (i != row && board[i][col] == board[row][col])
        {
            return false;
        }

        if (i != col && board[row][i] == board[row][col])
        {
            return false;
        }
    }

    int startX = (row / 3) * 3,
        startY = (col / 3) * 3;

    for (int i = startX; i < startX + 3; i++)
    {
        for (int j = startY; j < startY + 3; j++)
        {
            if (i != row && j != col && board[i][j] == board[row][col])
            {
                return false;
            }
        }
    }

    return true;
}

bool isValidSudokuValidateEachCell(char board[][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            char digit = board[i][j];
            if (digit >= '1' && digit <= '9' && !isValid(board, i, j))
            {
                return false;
            }
        }
    }

    return true;
}

bool isValidSudokuSet(char board[][9])
{
    unordered_set<string> seen{};
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                continue;
            }

            string digit(1, board[i][j]);
            digit.insert(0, "[");
            digit.append("]");

            if (
                !seen.insert(digit + to_string(i)).second ||
                !seen.insert(to_string(j) + digit).second ||
                !seen.insert(to_string(i / 3) + digit + to_string(j / 3)).second)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    char sudoku[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '5', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };

    if (isValidSudokuValidateEachCell(sudoku))
    {
        cout << "Valid!" << endl;
    }
    else
    {
        cout << "Invalid!" << endl;
    }

    return 0;
}
