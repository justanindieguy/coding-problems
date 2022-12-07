def print_triplets(title, triplets):
    print(title)
    for tup in triplets:
        print(tup)


def triplets_bruteforce(arr, s):
    n = len(arr)
    triplets = []

    if (n < 3):
        return triplets

    arr.sort()
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            for k in range(j + 1, n):
                if (arr[i] + arr[j] + arr[k] == s):
                    triplets.append((arr[i], arr[j], arr[k]))

    return triplets


def triplets(arr, s):
    n = len(arr)
    triplets = []

    if (n < 3):
        return triplets

    arr.sort()
    for i in range(0, n - 2):
        j = i + 1
        k = n - 1
        while (j < k):
            triplet_sum = arr[i] + arr[j] + arr[k]
            if triplet_sum == s:
                triplets.append((arr[i], arr[j], arr[k]))
                j += 1
                k -= 1
            elif triplet_sum < s:
                j += 1
            else:
                k -= 1

    return triplets


def main():
    target_sum = 18
    arr = [15, 2, 3, 5, 4, 6, 7, 8, 9, 1]

    print_triplets("Brute Force:", triplets_bruteforce(arr, target_sum))
    print_triplets("Pair Sum Approach:", triplets(arr, target_sum))


if __name__ == "__main__":
    main()
