from math import ceil, log2


def earth_level(n: int):
    m, lvl = 1, 0

    while m < n:
        m = m << 1
        lvl += 1

    return lvl


def earth_level_log(n: int):
    return ceil(log2(n))


def main():
    n = int(input())

    print(earth_level(n))
    print(earth_level_log(n))


if __name__ == "__main__":
    main()
