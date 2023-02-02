def count_bits(n: int):
    count = 0

    while n > 0:
        last_bit = n & 1
        count += last_bit
        n = n >> 1

    return count


def count_bits_hack(n: int):
    ans = 0

    while n > 0:
        n = n & (n - 1)
        ans += 1

    return ans


def main():
    n = int(input())

    print(count_bits(n))
    print(count_bits_hack(n))


if __name__ == "__main__":
    main()
