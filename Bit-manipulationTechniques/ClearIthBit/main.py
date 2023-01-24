def clear_ith_bit(n: int, i: int):
    mask = ~(1 << i)
    return n & mask


def main():
    n = 13
    i = int(input())

    n = clear_ith_bit(n, i)
    print(f"New n value: {n}")


if __name__ == "__main__":
    main()
