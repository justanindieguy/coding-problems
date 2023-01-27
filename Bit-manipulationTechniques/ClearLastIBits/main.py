def clear_last_i_bits(n: int, i: int):
    mask = -1 << i
    return n & mask


def main():
    n = 15
    i = int(input())

    n = clear_last_i_bits(n, i)
    print(n)


if __name__ == "__main__":
    main()
