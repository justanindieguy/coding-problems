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


# Sliding Window Approach - O(N)
def get_largest_unique_substring_sw(s: str):
    i, j = 0, 0
    start_window, window_length, max_window_length = -1, 0, 0
    occurrences = {}

    while j < len(s):
        ch = s[j]

        # Check if is inside hashmap and is in the current window.
        if ch in occurrences and occurrences[ch] >= i:
            i = occurrences[ch] + 1
            # Update remaining window length excluding current char.
            window_length = j - i

        # Update the last occurrence.
        occurrences[ch] = j
        window_length += 1
        j += 1

        # Update max_window_length at every step.
        if window_length > max_window_length:
            max_window_length = window_length
            start_window = i

    end_window = start_window + max_window_length
    return s[start_window:end_window]


def main():
    s = input()
    print(get_largest_unique_substring_sw(s))


if __name__ == "__main__":
    main()
