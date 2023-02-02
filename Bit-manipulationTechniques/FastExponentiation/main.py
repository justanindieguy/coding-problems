def fast_exponentiation(a: int, n: int):
    ans = 1

    while n > 0:
        last_bit = n & 1

        if last_bit:
            ans *= a

        a *= a
        n = n >> 1

    return ans


def main():
    a = int(input())
    n = int(input())

    print(fast_exponentiation(a, n))


if __name__ == "__main__":
    main()
