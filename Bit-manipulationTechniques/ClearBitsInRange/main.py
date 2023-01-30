def clear_bits_in_range(n: int, i: int, j: int):
    a = -1 << (j + 1)
    b = (1 << i) - 1
    mask = a | b

    return n & mask


def main():
    n, i, j = 31, 1, 3

    n = clear_bits_in_range(n, i, j)
    print(n)


if __name__ == "__main__":
    main()
