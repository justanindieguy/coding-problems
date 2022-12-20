def maximum_sub_array_sum(arr: list[int]):
    max_so_far = float("-inf")
    max_till_now = 0

    for num in arr:
        max_till_now += num
        if max_so_far < max_till_now:
            max_so_far = max_till_now
        if max_till_now < 0:
            max_till_now = 0

    if max_so_far < 0:
        max_so_far = 0

    return max_so_far


def main():
    arr = [-1, 2, 3, 4, -2, 6, -8, 3]
    print(maximum_sub_array_sum(arr))


if __name__ == "__main__":
    main()
