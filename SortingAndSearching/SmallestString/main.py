def merge(strings: list[str], start: int, end: int):
    mid = (start + end) // 2

    temp = []
    i = start
    j = mid + 1
    while i <= mid and j <= end:
        x = strings[i] + strings[j]
        y = strings[j] + strings[i]

        if x < y:
            temp.append(strings[i])
            i += 1
        else:
            temp.append(strings[j])
            j += 1

    while i <= mid:
        temp.append(strings[i])
        i += 1

    while j <= end:
        temp.append(strings[j])
        j += 1

    k = 0
    for idx, num in enumerate(strings[start:end+1], start=start):
        strings[idx] = temp[k]
        k += 1


def merge_sort(strings: list[str], start: int, end: int):
    if start >= end:
        return

    mid = (start + end) // 2
    merge_sort(strings, start, mid)
    merge_sort(strings, mid + 1, end)

    merge(strings, start, end)


def main():
    strings = ["a", "ab", "aba"]

    n = len(strings)
    merge_sort(strings, 0, n - 1)

    for s in strings:
        print(s, end="")

    print()


if __name__ == "__main__":
    main()
