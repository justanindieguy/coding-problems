def rotated_search(l: list[int], k: int):
    n = len(l)
    start, end = 0, n - 1

    while start <= end:
        mid = (start + end) // 2

        if l[mid] == k:
            return mid

        if l[start] <= l[mid]:
            if k >= l[start] and k <= l[mid]:
                end = mid - 1
            else:
                start = mid + 1
        else:
            if k >= l[mid] and k <= l[end]:
                start = mid + 1
            else:
                end = mid - 1

    return - 1


def main():
    k = int(input())
    l = [4, 5, 6, 7, 0, 1, 2, 3]
    print(rotated_search(l, k))


if __name__ == "__main__":
    main()
