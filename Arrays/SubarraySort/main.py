def sub_array_sort_sorting(arr: list[int]):
    n = len(arr)
    sorted_arr = sorted(arr)

    i = 0
    while i < n and arr[i] == sorted_arr[i]:
        i += 1

    j = n - 1
    while i > -1 and arr[j] == sorted_arr[j]:
        j -= 1

    if i == n:
        return (-1, -1)

    return (i, j)


def out_of_order(arr: list[int], i: int):
    num = arr[i]

    if i == 0:
        return num > arr[1]

    if i == len(arr) - 1:
        return num < arr[i - 1]

    return num > arr[i + 1] or num < arr[i - 1]


def sub_array_sort_linear(arr: list[int]):
    n = len(arr)
    smallest = float("inf")
    greatest = float('-inf')
    for i, num in enumerate(arr):
        num = arr[i]
        if out_of_order(arr, i):
            smallest = min(smallest, num)
            greatest = max(greatest, num)

    if smallest == float("inf"):
        return (-1, -1)

    start = 0
    while smallest >= arr[start]:
        start += 1

    end = n - 1
    while end <= arr[end]:
        end -= 1

    return (start, end)


def main():
    arr = [1, 2, 3, 4, 10, 8, 5, 12, 6, 13, 14, 15]
    print(f"Sorting: {sub_array_sort_sorting(arr)}")
    print(f"Linear: {sub_array_sort_linear(arr)}")


if __name__ == "__main__":
    main()
