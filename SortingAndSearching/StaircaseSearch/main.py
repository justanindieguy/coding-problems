def staircase_search_brute(matrix: list[list[int]], k: int):
    for i, row in enumerate(matrix):
        for j, num in enumerate(row):
            if num == k:
                return (i, j)

    return (-1, -1)


def staircase_search_linear(matrix: list[list[int]], k: int):
    rows = len(matrix)
    cols = len(matrix[0])
    row, col = 0, cols - 1

    while row < rows and col > -1:
        curr = matrix[row][col]

        if curr == k:
            return (row, col)

        if k > curr:
            row += 1
        else:
            col -= 1

    return (-1, -1)


def staircase_binary_search(matrix: list[list[int]], k: int):
    rows = len(matrix)
    cols = len(matrix[0])

    start, end = 0, rows * cols - 1
    while start <= end:
        mid = (start + end) // 2
        row_idx, col_idx = mid // cols, mid % cols
        num = matrix[row_idx][col_idx]

        if num == k:
            return (row_idx, col_idx)

        if num > k:
            end = mid - 1
        else:
            start = mid + 1

    return (-1, -1)


def main():
    matrix = [
        [1, 3, 5, 7],
        [10, 11, 16, 20],
        [23, 30, 34, 60],
    ]

    k = int(input())
    print(staircase_search_brute(matrix, k))


if __name__ == "__main__":
    main()
