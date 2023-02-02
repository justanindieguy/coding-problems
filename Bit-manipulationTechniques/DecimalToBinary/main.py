def convert_to_binary(n: int):
    ans = 0
    exp = 1

    while n > 0:
        ans += (n % 2) * exp
        exp *= 10
        n = n // 2

    return ans


def main():
    n = int(input())
    print(convert_to_binary(n))


if __name__ == "__main__":
    main()
