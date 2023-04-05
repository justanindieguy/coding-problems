def partition(arr: list[int], start: int, end: int):
    pivot = arr[end]

    i = start - 1
    for j, num in enumerate(arr[start:end], start=start):
        if num < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[end] = arr[end], arr[i + 1]
    return i + 1


def quick_select(arr: list[int], start: int, end: int, k: int):
    p = partition(arr, start, end)
    if p == k - 1:
        return arr[p]
    elif k - 1 < p:
        return quick_select(arr, start, p - 1, k)
    else:
        return quick_select(arr, p + 1, end, k)


def main():
    k = int(input())

    arr = [10, 5, 2, 0, 7, 6, 4]
    n = len(arr)

    if k > n:
        print("-1")
    else:
        print(quick_select(arr, 0, n - 1, k))


if __name__ == "__main__":
    main()
