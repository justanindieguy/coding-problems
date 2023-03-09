def merge(arr: list[int], start: int, end: int):
    mid = (start + end) // 2
    i = start
    j = mid + 1

    temp = []
    while i <= mid and j <= end:
        if arr[i] < arr[j]:
            temp.append(arr[i])
            i += 1
        else:
            temp.append(arr[j])
            j += 1

    while i <= mid:
        temp.append(arr[i])
        i += 1

    while j <= end:
        temp.append(arr[j])
        j += 1

    k = 0
    for idx, num in enumerate(arr[start:end+1], start=start):
        arr[idx] = temp[k]
        k += 1

    return arr


def merge_sort(arr: list[int], start: int, end: int):
    if start >= end:
        return

    mid = (start + end) // 2
    merge_sort(arr, start, mid)
    merge_sort(arr, mid + 1, end)

    return merge(arr, start, end)


def main():
    arr = [10, 5, 2, 0, 7, 6, 4]
    start = 0
    end = len(arr) - 1

    arr = merge_sort(arr, start, end)
    print(arr)


if __name__ == "__main__":
    main()
