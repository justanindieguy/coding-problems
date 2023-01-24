def get_ith_bit(n: int, i: int):
    mask = 1 << i
    return 1 if (n & mask) > 0 else 0


def main():
    n = 5
    i = int(input())

    print(f"Bit at {i}th position: {get_ith_bit(n, i)}")


if __name__ == "__main__":
    main()
