def bubble_sort(l: list[int]):
    n = len(l)

    has_swapped = True
    while has_swapped:
        has_swapped = False
        for i, num in enumerate(l[:n - 1]):
            if num > l[i+1]:
                l[i], l[i + 1] = l[i + 1], l[i]
                has_swapped = True


def optimized_bubble_sort(l: list[int]):
    n = len(l)
    has_swapped = False
    for i in range(n - 1):
        has_swapped = False
        for j, num in enumerate(l[:n - i - 1]):
            if num > l[j + 1]:
                l[j], l[j + 1] = l[j + 1], l[j]
                has_swapped = True

        if not has_swapped:
            break


def main():
    l = [7, 3, 2, 1, 5, 6, 10, 9, 8]
    optimized_bubble_sort(l)
    print(l)


if __name__ == "__main__":
    main()
