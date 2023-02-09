from bisect import bisect_left


def get_prefix_sum_list_recursion(l: list[int], ps: list[int], i: int):
    if i == len(l):
        return
    if i == 0:
        ps.append(l[i])
    else:
        ps.append(ps[i - 1] + l[i])

    get_prefix_sum_list_recursion(l, ps, i + 1)


def get_prefix_sum_list(l: list[int]):
    curr_sum = 0
    sums: list[int] = []

    for num in l:
        curr_sum += num
        sums.append(curr_sum)

    return sums


def housing(l: list[int], ps: list[int], k: int):
    indices = []

    for start, x in enumerate(l):
        for end, y in enumerate(l[start:], start=start):
            area = ps[end] if (start == 0) else (ps[end] - ps[start - 1])

            if area == k:
                indices.append((start, end))

    return indices


def housing_binary_search(ps: list[int], k: int):
    indices = []

    for i, n in enumerate(ps):
        if n == k:
            indices.append((0, i))
            continue

        j = bisect_left(ps, n - k)
        if n - ps[j] == k:
            indices.append((j + 1, i))

    return indices


def housing_sliding_window(l: list[int], k: int):
    n = len(l)
    i, j, cs = 0, 0, 0
    indices = []

    while j < n:
        cs += l[j]
        j += 1

        while cs > k and i < j:
            cs -= l[i]
            i += 1

        if cs == k:
            indices.append((i, j - 1))

    return indices


def housing_smallest_window(l: list[int], k: int):
    n = len(l)
    i, j, cs, sd = 0, 0, 0, float("inf")
    sw = (-1, -1)

    while j < n:
        cs += l[j]
        j += 1

        while cs > k and i < j:
            cs -= l[i]
            i += 1

        cd = j - i
        if cs == k and cd < sd:
            sd = cd
            sw = (i, j - 1)

    return sw


def main():
    k = int(input())

    # l = [2, 1, 4, 1, 3, 2, 1, 1, 2, 1, 3]
    # ps = get_prefix_sum_list(l)

    l = [1, 3, 2, 1, 4, 1, 3, 2, 1, 1, 2]
    sw = housing_smallest_window(l, k)
    print(sw)


if __name__ == "__main__":
    main()
