def compress_string(s: str):
    if len(s) <= 1:
        return s

    total = 1
    curr = s[0]
    output = []
    for char in s[1:]:
        if char == curr:
            total += 1
        else:
            output.extend([curr, str(total)])
            total = 1
            curr = char
    output.extend([curr, str(total)])

    if len(output) > len(s):
        return s

    return "".join(output)


def main():
    s = input()
    print(compress_string(s))


if __name__ == "__main__":
    main()
