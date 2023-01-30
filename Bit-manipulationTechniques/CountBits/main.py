def count_bits(n: int):
    count = 0

    while n > 0:
        last_bit = n & 1
        count += last_bit
        n = n >> 1

    return count


def main():
    n = int(input())
    print(count_bits(n))


if __name__ == "__main__":
    main()
