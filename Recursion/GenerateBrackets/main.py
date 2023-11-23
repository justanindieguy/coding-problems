def generate_brackets(output: str, n: int, open: int, close: int, i: int):
    if (i == 2 * n):
        print(output)
        return

    if open < n:
        generate_brackets(output + "(", n, open + 1, close, i + 1)

    if close < open:
        generate_brackets(output + ")", n, open, close + 1, i + 1)


def main():
    output = ""
    n = int(input())
    generate_brackets(output, n, 0, 0, 0)


if __name__ == "__main__":
    main()
