def count(arr: list[int], start: int, end: int):
    mid = (start + end) // 2
    i = start
    j = mid + 1

    temp = []
    count = 0

    while i <= mid and j <= end:
        if arr[i] < arr[j]:
            temp.append(arr[i])
            i += 1
        else:
            count += mid - i + 1
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

    return count


# Recursive Approach - O(N log N)
def count_inversions(arr: list[int], start: int, end: int):
    if start >= end:
        return 0

    mid = (start + end) // 2
    c1 = count_inversions(arr, start, mid)
    c2 = count_inversions(arr, mid + 1, end)
    cross_count = count(arr, start, end)

    return c1 + c2 + cross_count


def main():
    l = [0, 5, 2, 3, 1]
    start = 0
    end = len(l) - 1

    print(count_inversions(l, start, end))


if __name__ == "__main__":
    main()
