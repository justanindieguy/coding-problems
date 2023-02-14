def get_substrings(s: str):
    substrings = []

    for i, char1 in enumerate(s):
        for j, char2 in enumerate(s[i:], start=i):
            substrings.append(s[i:j+1])

    return substrings


def has_every_character(s1: str, s2: str):
    last_char = ""
    for char in s2:
        if char == last_char:
            continue

        last_char = char
        n = s2.count(char)
        m = s1.count(char)

        if m < n:
            return False

    return True


def find_window_brute_force(s2: str, substrings: list[str]):
    smallest_substring = ""
    smallest_len = float("inf")

    for substring in substrings:
        substring_len = len(substring)
        if has_every_character(substring, s2) and substring_len < smallest_len:
            smallest_len = substring_len
            smallest_substring = substring

    return smallest_substring


def main():
    s1 = input("s1: ")
    s2 = input("s2: ")
    substrings = get_substrings(s1)
    print(find_window_brute_force(s2, substrings))


if __name__ == "__main__":
    main()
