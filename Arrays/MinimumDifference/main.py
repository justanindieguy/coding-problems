def min_diff_brute_force(arr1: list[int], arr2: list[int]):
    minimum_pair = (0, 0)
    min_diff = float("inf")
    for num1 in arr1:
        for num2 in arr2:
            diff = abs(num1 - num2)
            if diff < min_diff:
                min_diff = diff
                minimum_pair = (num1, num2)

    return minimum_pair


def min_diff(arr1: list[int], arr2: list[int]):
    minimum_pair = (0, 0)
    min_diff = float("inf")

    arr1.sort()
    arr2.sort()

    n = len(arr1)
    m = len(arr2)
    i = j = 0
    while i < n and j < m:
        diff = abs(arr1[i] - arr2[j])
        if diff < min_diff:
            min_diff = diff
            minimum_pair = (arr1[i], arr2[j])

        if arr1[i] < arr2[j]:
            i += 1
        else:
            j += 1

    return minimum_pair


def main():
    arr1 = [23, 5, 10, 17, 30]
    arr2 = [26, 134, 135, 14, 19]
    print(min_diff_brute_force(arr1, arr2))
    print(min_diff(arr1, arr2))


if __name__ == "__main__":
    main()
