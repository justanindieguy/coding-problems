def set_ith_bit(n: int, i: int):
    mask = (1 << i)
    return (n | mask)


def main():
    n = 5
    i = int(input())

    n = set_ith_bit(n, i)
    print(f"New value of n: {n}")


if __name__ == "__main__":
    main()
