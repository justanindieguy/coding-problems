def sparse_search(l: list[str], key: str):
    n = len(l)

    start = 0
    end = n - 1
    while start <= end:
        mid = (start + end) // 2

        mid_left = mid - 1
        mid_right = mid + 1

        if l[mid] == "":
            while True:
                if mid_left < start and mid_right > end:
                    return -1
                elif mid_left >= start and l[mid_left] != "":
                    mid = mid_left
                    break
                elif mid_right <= end and l[mid_right] != "":
                    mid = mid_right
                    break

                mid_left -= 1
                mid_right += 1

        if l[mid] == key:
            return mid
        elif l[mid] > key:
            end = mid - 1
        else:
            start = mid + 1

    return -1


def main():
    l = ["ai", "", "", "bat", "", "", "car", "cat", "", "", "dog"]

    key = input()
    print(sparse_search(l, key))


if __name__ == "__main__":
    main()
