def clear_bits_in_range(n: int, i: int, j: int):
    a = (-1) << (j + 1)
    b = (1 << i) - 1
    mask = a | b
    return n & mask


def replace_bits_in_range(n: int, m: int, i: int, j: int):
    n = clear_bits_in_range(n, i, j)
    mask = m << i
    return n | mask


def main():
    n, m, i, j = 512, 21, 2, 6

    n = replace_bits_in_range(n, m, i, j)
    print(n)


if __name__ == "__main__":
    main()
