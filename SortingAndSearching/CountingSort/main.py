def counting_sort(l: list[int]):
    max_el = max(l)
    cnt_list = [0] * (max_el + 1)
    output = [0] * len(l)

    for num in l:
        cnt_list[num] += 1

    for i, num in enumerate(cnt_list[1:], start=1):
        cnt_list[i] += cnt_list[i - 1]

    for i, num in enumerate(l):
        correct_pos = cnt_list[num] - 1
        cnt_list[num] -= 1
        output[correct_pos] = num

    for i, num in enumerate(output):
        l[i] = num


def main():
    l = [4, 2, 2, 8, 3, 3, 1]
    counting_sort(l)
    print(l)


if __name__ == "__main__":
    main()
