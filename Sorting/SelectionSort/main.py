def selection_sort(l: list[int]):
    for i, num1 in enumerate(l):
        min_index = i
        for j, num2 in enumerate(l[i+1:], start=i+1):
            if num2 < num1:
                min_index = j

        l[min_index], l[i] = l[i], l[min_index]


def main():
    nums = [7, 3, 2, 5, 6, 10, 9, 8, 1]
    selection_sort(nums)

    print(nums)


if __name__ == "__main__":
    main()
