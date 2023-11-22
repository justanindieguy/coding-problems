def count_subsets_with_target_sum(arr_set: list[int], n: int, start: int, target_sum: int):
    if start == n:
        if target_sum == 0:
            return 1
        return 0

    inc = count_subsets_with_target_sum(
        arr_set, n, start + 1, target_sum - arr_set[start])

    exc = count_subsets_with_target_sum(arr_set, n, start + 1, target_sum)

    return inc + exc


def main():
    target_sum = 6
    arr_set = [1, 2, 3, 4, 5]
    print(count_subsets_with_target_sum(arr_set, len(arr_set), 0, target_sum))


if __name__ == "__main__":
    main()
