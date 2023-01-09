def break_palindrome(palindrome: str):
    n = len(palindrome)

    if n <= 1:
        return ""

    is_odd = n % 2 != 0
    mid_idx = n // 2
    output = list(palindrome)

    for idx, char in enumerate(palindrome):
        if is_odd and idx == mid_idx:
            continue
        if char != "a":
            output[idx] = "a"
            return "".join(output)
        if idx == n - 1:
            output[idx] = "b"
            return "".join(output)


def main():
    palindrome = input()
    print(break_palindrome(palindrome))


if __name__ == "__main__":
    main()
