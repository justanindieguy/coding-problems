def partition(arr: list[int], start: int, end: int):
    pivot = arr[end]

    i = start - 1
    for j, num in enumerate(arr[start:end], start=start):
        if num < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[end] = arr[end], arr[i + 1]
    return i + 1


def quick_sort(arr: list[int], start: int, end: int):
    if start >= end:
        return

    p = partition(arr, start, end)
    quick_sort(arr, start, p - 1)
    quick_sort(arr, p + 1, end)


def main():
    arr = [10, 5, 2, 0, 7, 6, 4]

    n = len(arr)
    quick_sort(arr, 0, n - 1)

    print(arr)


if __name__ == "__main__":
    main()
