def sub_array_sorting(l: list[int]):
    s = sorted(l)

    i = 0
    n = len(l)
    while i < n and l[i] == s[i]:
        i += 1

    j = n - 1
    while j >= 0 and l[j] == s[j]:
        j -= 1

    if i == n:
        return (-1, -1)

    return (i, j)


def sub_array_sorting_linear(l: list[int]):
    n = len(l) - 1
    end = -1
    curr_max = l[0]

    is_sorted = True

    for i, num in enumerate(l[1:], start=1):
        if num < curr_max:
            end = i
            is_sorted = False
        else:
            curr_max = num

    start = -1
    curr_min = l[n]
    for i, num in reversed(list(enumerate(l[:n]))):
        if num > curr_min:
            start = i
        else:
            curr_min = num

    if is_sorted:
        return (-1, -1)

    return (start, end)


def main():
    l = [0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29]
    print(sub_array_sorting_linear(l))


if __name__ == "__main__":
    main()
