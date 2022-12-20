def longest_band_sorting(arr: list[int]):
    n = len(arr)
    max_length = 0
    band_length = 1

    if (n == 1):
        return band_length

    arr.sort()
    for i in range(n - 1):
        if arr[i] + 1 == arr[i + 1]:
            band_length += 1
        else:
            max_length = max(max_length, band_length)
            band_length = 1

    return max_length


def longest_band_my_solution(arr: list[int]):
    max_length = 0
    present = set(arr)
    checked = set()

    for curr in arr:
        if curr in checked:
            continue

        band_length = 1
        prev_num = curr - 1
        next_num = curr + 1
        checked.add(curr)

        while prev_num in present:
            band_length += 1
            prev_num -= 1
            checked.add(prev_num)

        while next_num in present:
            band_length += 1
            next_num += 1
            checked.add(next_num)

        max_length = max(max_length, band_length)

    return max_length


# * Best solution
def longest_band_sets(arr: list[int]):
    max_length = 0
    present = set(arr)

    for curr in arr:
        # Check whether current element is head of a band or not...
        # If it is NOT A HEAD, then ignore it
        prev_num = curr - 1
        if prev_num in present:
            continue

        # If it is a HEAD, get the band length
        band_length = 1
        next_num = curr + 1
        while next_num in present:
            band_length += 1
            next_num += 1

        max_length = max(max_length, band_length)

    return max_length


def main():
    arr = [1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6]
    print(f"Sorting: {longest_band_sorting(arr)}")
    print(f"Sets: {longest_band_sets(arr)}")
    print(f"Sets (my solution): {longest_band_my_solution(arr)}")


if __name__ == "__main__":
    main()
