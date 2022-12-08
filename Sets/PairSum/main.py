def binary_search(arr: list[int], n: int):
    low = 0
    high = len(arr) - 1
    mid = 0

    while low <= high:
        mid = (high + low) // 2
        if arr[mid] < n:
            low = mid + 1
        elif arr[mid] > n:
            high = mid - 1
        else:
            return mid

    return -1


def pair_sum_bruteforce(arr: list[int], s: int):
    length = len(arr)
    for i in range(length):
        for j in range(length - 1):
            pair_sum = arr[i] + arr[j]
            if pair_sum == s:
                print(f"{arr[i]}, {arr[j]}")


def pair_sum_two_pointers(arr: list[int], s: int):
    length = len(arr)

    i = 0
    j = length - 1
    sorted_arr = sorted(arr)
    while i < j:
        pair_sum = sorted_arr[i] + sorted_arr[j]
        if pair_sum == s:
            print(f"{sorted_arr[i]}, {sorted_arr[j]}")
            i += 1
            j -= 1
        elif pair_sum < s:
            i += 1
        else:
            j -= 1


def pair_sum_binary_search(arr: list[int], s: int):
    already_paired = set()
    sorted_arr = sorted(arr)
    for idx, num in enumerate(sorted_arr):
        if num in already_paired:
            continue

        find = s - num
        if binary_search(sorted_arr, find) > -1:
            print(f"{num}, {find}")
            already_paired.add(find)


def pair_sum_set(arr: list[int], s: int):
    traversed = set()
    for idx, num in enumerate(arr):
        find = s - num
        if find in traversed:
            print(f"{num}, {find}")

        traversed.add(num)


def main():
    target_sum = 8
    arr = [2, 1, 8, 6, -2, 5, 3, 0]

    print("Brute Force:")
    pair_sum_bruteforce(arr, target_sum)

    print("Two Pointers:")
    pair_sum_two_pointers(arr, target_sum)

    print("Binary Search:")
    pair_sum_binary_search(arr, target_sum)

    print("Sets:")
    pair_sum_set(arr, target_sum)


if __name__ == "__main__":
    main()
