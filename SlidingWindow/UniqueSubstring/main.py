def has_unique_characters(s: str):
    return len(s) == len(set(s))


# Brute-Force Approach - O(N^3)
def get_largest_unique_substring(s: str):
    chars = list(s)

    largest_substring = ""
    for i, char1 in enumerate(chars):
        for j, char2 in enumerate(chars[i:], start=i):
            substring = "".join(chars[i:j+1])
            is_larger = len(substring) > len(largest_substring)

            if has_unique_characters(substring) and is_larger:
                largest_substring = substring

    return largest_substring


def main():
    s = input()
    print(get_largest_unique_substring(s))


if __name__ == "__main__":
    main()
