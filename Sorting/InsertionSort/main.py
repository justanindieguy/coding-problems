def insertion_sort(l: list[int]):
    for i, current_num in enumerate(l[1:], start=1):
        current_idx = i
        while current_idx > 0 and l[current_idx - 1] > current_num:
            l[current_idx], l[current_idx - 1] = l[current_idx - 1], l[current_idx]
            current_idx -= 1


def main():
    l = [7, 3, 2, 5, 6, 10, 9, 8, 1]
    insertion_sort(l)
    print(l)


if __name__ == "__main__":
    main()
