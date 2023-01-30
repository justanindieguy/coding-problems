def is_power_of_two(n: int):
    if (n & (n - 1)) == 0:
        print("Power of two")
    else:
        print("Not a power of two")


def main():
    n = 16
    is_power_of_two(n)


if __name__ == "__main__":
    main()
