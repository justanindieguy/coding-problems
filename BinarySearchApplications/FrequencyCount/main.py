def freq_count_linear_search(l: list[int], k: int):
    freq = 0
    for n in l:
        if n == k:
            freq += 1

    return freq


def get_lower_bound(l: list[int], k: int):
    n = len(l)
    start, end = 0, n - 1

    lower_bound = -1
    while start <= end:
        mid = (start + end) // 2
        num = l[mid]

        if num == k:
            lower_bound = mid
            end = mid - 1
        elif num < k:
            start = mid + 1
        else:
            end = mid - 1

    return lower_bound


def get_upper_bound(l: list[int], k: int):
    n = len(l)
    start, end = 0, n - 1

    upper_bound = -1
    while start <= end:
        mid = (start + end) // 2
        num = l[mid]

        if num == k:
            upper_bound = mid
            start = mid + 1
        elif num < k:
            start = mid + 1
        else:
            end = mid - 1

    return upper_bound


def freq_count_binary_search(l: list[int], k: int):
    lower_bound = get_lower_bound(l, k)

    if lower_bound == -1:
        return 0

    upper_bound = get_upper_bound(l, k)

    return upper_bound - lower_bound + 1


def main():
    k = int(input())
    l = [0, 1, 1, 1, 1, 2, 2, 2, 3, 4, 4, 5, 10]
    print("Frequency Count:", freq_count_linear_search(l, k))
    print("Frequency Count:", freq_count_binary_search(l, k))


if __name__ == "__main__":
    main()
