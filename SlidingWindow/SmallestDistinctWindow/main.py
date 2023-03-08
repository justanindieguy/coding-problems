from collections import Counter


def get_smallest_distinct_window(string: str):
    unique_chars = len(set(string))
    freq_string = Counter()

    matches = 0
    start = 0
    start_idx = -1
    smallest_window_len = float("inf")
    for i, char in enumerate(string):
        if freq_string[char] == 0:
            matches += 1

        freq_string[char] += 1

        if matches == unique_chars:
            while matches == unique_chars:
                freq_string[string[start]] -= 1

                if freq_string[string[start]] == 0:
                    matches -= 1

                start += 1

            window_start = start - 1
            window_length = i - window_start + 1
            if window_length < smallest_window_len:
                start_idx = window_start
                smallest_window_len = window_length

    if start_idx == -1:
        return "Window not found!"

    end_idx = start_idx + smallest_window_len
    return string[start_idx:end_idx]


def main():
    string = "aabcbcdbcaaad"
    print(get_smallest_distinct_window(string))


if __name__ == "__main__":
    main()
