from collections import Counter


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


def find_window_sliding_window(s: str, pattern: str):
    freq_s = Counter()
    freq_pattern = Counter(pattern)

    cnt = 0
    start = 0
    start_idx = -1
    min_so_far = float("inf")
    window_size = 0

    for i, ch in enumerate(s):
        freq_s[ch] += 1

        if freq_pattern[ch] != 0 and freq_s[ch] <= freq_pattern[ch]:
            cnt += 1

        if cnt == len(pattern):
            while freq_pattern[s[start]] == 0 or freq_s[s[start]] > freq_pattern[s[start]]:
                freq_s[s[start]] -= 1
                start += 1

            window_size = i - start + 1
            if window_size < min_so_far:
                min_so_far = window_size
                start_idx = start

    if start_idx == -1:
        return "No window found!"

    return s[start:start+min_so_far]


def main():
    s1 = input("s1: ")
    s2 = input("s2: ")

    # substrings = get_substrings(s1)
    # print(get_smallest_substring(s2, substrings))

    print(find_window_sliding_window(s1, s2))


if __name__ == "__main__":
    main()
