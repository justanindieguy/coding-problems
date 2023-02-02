def clear_ith_bit(n: int, i: int):
    mask = ~(1 << i)
    return n & mask


def update_ith_bit(n: int, i: int, v: int):
    n = clear_ith_bit(n, i)

    mask = (v << i)
    return n | mask  # Sets the right value


def main():
    n = 13
    i = int(input())

    n = update_ith_bit(n, i, 0)
    print(n)


if __name__ == "__main__":
    main()
