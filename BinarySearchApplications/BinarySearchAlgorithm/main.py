def binary_search(l: list[int], k: int):
    n = len(l)
    start, end = 0, n - 1

    while start <= end:
        mid = (start + end) // 2
        num = l[mid]

        if num == k:
            return mid

        if num < k:
            start = mid + 1
        else:
            end = mid - 1

    return -1


def recursive_binary_search(l: list[int], k: int, start: int, end: int):
    if start > end:
        return -1

    mid = (start + end) // 2
    num = l[mid]

    if num == k:
        return mid

    if num < k:
        return recursive_binary_search(l, k, mid + 1, end)
    else:
        return recursive_binary_search(l, k, start, mid - 1)


def main():
    l = [1, 2, 10, 11, 19, 28, 29]
    k = int(input())

    print(binary_search(l, k))
    print(recursive_binary_search(l, k, 0, len(l) - 1))


if __name__ == "__main__":
    main()
