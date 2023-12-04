"""
N-Queen is the problem of placing N chess queens on an NxN chessboard so that
no two queens attack each other

Input:
4

Output:

2D Matrix with Queens

0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0
"""


def print_board(n: int, board: list[list[int]]):
    for row in board[0:n]:
        for col in row[0:n]:
            print(col, end=" ")
        print()


def can_place(board: list[list[int]], n: int, x: int, y: int):
    # Columns
    for k, val in enumerate(board[0:x]):
        if board[k][y]:
            return False

    # Left Diagonal
    i = x
    j = y
    while i >= 0 and j >= 0:
        if board[i][j]:
            return False

        i -= 1
        j -= 1

    # Right Diagonal
    i = x
    j = y
    while i >= 0 and j < n:
        if board[i][j]:
            return False

        i -= 1
        j += 1

    return True


def solve_N_queen(n: int, board: list[list[int]], i: int):
    # Base case
    if i == n:
        print_board(n, board)
        return True

    # Recursive case
    # Try to place a queen in every row
    for j, val in enumerate(board[i][0:n]):
        # Check whether the current i, j position is safe or not
        if can_place(board, n, i, j):
            board[i][j] = 1  # Put
            success = solve_N_queen(n, board, i + 1)

            if success:
                return True

            # Backtrack
            board[i][j] = 0  # Remove

    # There is no valid position for a queen in the current row
    return False


def main():
    board = [[0 for col in range(20)] for row in range(20)]

    n = int(input())

    solve_N_queen(n, board, 0)


if __name__ == "__main__":
    main()
