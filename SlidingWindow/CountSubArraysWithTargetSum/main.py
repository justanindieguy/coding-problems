from itertools import accumulate
from collections import Counter


# Brute-Force Approach - O(N^3)
def count_sub_arrays_with_target_sum_brute(l: list[int], target: int):
    count = 0

    for i, num1 in enumerate(l):
        for j, num2 in enumerate(l[i:], start=i):
            sub_array = l[i:j+1]
            if sum(sub_array) == target:
                count += 1

    return count


# Optimized with Prefix Sum - O(N^2)
def calculate_sub_array_sum(prefix_sum: list[int], i: int, j: int):
    return prefix_sum[j] if i == 0 else prefix_sum[j] - prefix_sum[i - 1]


def count_sub_arrays_with_target_sum_prefix_sum(l: list[int], target: int):
    prefix_sum = list(accumulate(l))

    count = 0
    for i, num1 in enumerate(l):
        for j, num2 in enumerate(l[i:], start=i):
            if calculate_sub_array_sum(prefix_sum, i, j) == target:
                count += 1

    return count


# Optimized Space Complexity to O(1)
def count_sub_arrays_with_target_sum_space(l: list[int], target: int):
    count = 0
    for i, num1 in enumerate(l):
        sub_array_sum = 0
        for num2 in l[i:]:
            sub_array_sum += num2
            if sub_array_sum == target:
                count += 1

    return count


def count_sub_arrays_with_target_sum_hash(l: list[int], target: int):
    count, curr_sum = 0, 0
    prefix_sum = Counter()
    for num in l:
        curr_sum += num

        if curr_sum == target:
            count += 1

        diff = curr_sum - target
        if diff in prefix_sum:
            count += prefix_sum[diff]

        prefix_sum[curr_sum] += 1

    return count


def main():
    target = int(input("Enter target sum: "))
    l = [3, 4, 7, 2, -3, 1, 4, 2]

    count = count_sub_arrays_with_target_sum_hash(l, target)
    print(count)


if __name__ == "__main__":
    main()
