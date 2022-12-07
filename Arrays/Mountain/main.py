def highest_mountain(arr):
    largest = 0
    n = len(arr)

    i = 1
    while (i <= n - 2):
        if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1]):
            count = 1
            j = i

            while (j >= 1 and arr[j] > arr[j - 1]):
                j -= 1
                count += 1

            while (i <= n - 2 and arr[i] > arr[i + 1]):
                i += 1
                count += 1

            largest = max(count, largest)
        else:
            i += 1

    return largest


def main():
    arr = [5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4]
    print(f"Highest Mountain Length: {highest_mountain(arr)}")


if __name__ == "__main__":
    main()
