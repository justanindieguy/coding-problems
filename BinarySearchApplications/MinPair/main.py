from bisect import bisect_left


def brute_force_approach(l1: list[int], l2: list[int]):
    min_diff = float("inf")
    ans = (-1, -1)

    for num1 in l1:
        for num2 in l2:
            diff = abs(num1 - num2)
            if diff < min_diff:
                min_diff = diff
                ans = (num1, num2)

    return ans


def binary_search_approach(l1: list[int], l2: list[int]):
    l2.sort()

    min_diff = float("inf")
    ans = (-1, -1)

    # Iterate over the first array and look for closest element in the second array
    for x in l1:
        lb = bisect_left(l2, x)

        # Check immediate smallest element (left)
        if lb > 0 and x - l2[lb - 1] < min_diff:
            min_diff = x - l2[lb - 1]
            ans = (x, l2[lb - 1])

        # Check immediate greater element (right)
        if lb != len(l2) and l2[lb] - x < min_diff:
            min_diff = l2[lb] - x
            ans = (x, l2[lb])

    return ans


def main():
    l1 = [-1, 5, 10, 20, 3]
    l2 = [26, 134, 135, 15, 17]

    print(brute_force_approach(l1, l2))
    print(binary_search_approach(l1, l2))


if __name__ == "__main__":
    main()
