def sort_two_colors(colors: list[int]):
    n = len(colors)
    low, high = 0, n - 1
    while low <= high:
        if colors[low] == 0:
            low += 1
        elif colors[low] == 1:
            colors[low], colors[high] = colors[high], colors[low]
            high -= 1


def sort_three_colors(colors: list[int]):
    n = len(colors)
    low, mid, high = 0, 0, n - 1
    while mid <= high:
        if colors[mid] == 0:
            colors[low], colors[mid] = colors[mid], colors[low]
            low += 1
            mid += 1
        elif colors[mid] == 1:
            mid += 1
        elif colors[mid] == 2:
            colors[mid], colors[high] = colors[high], colors[mid]
            high -= 1


def main():
    two_colors = [0, 1, 1, 0, 1, 0, 1, 1, 1, 1]
    sort_two_colors(two_colors)
    print(two_colors)

    three_colors = [2, 0, 2, 1, 1, 0]
    sort_three_colors(three_colors)
    print(three_colors)


if __name__ == "__main__":
    main()
