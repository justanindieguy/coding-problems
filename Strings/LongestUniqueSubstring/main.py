from collections import Counter


def linear_approach(s: str):
    left_bound = 0
    freq_map = Counter()
    max_window_size = 0

    for right_bound, current_char in enumerate(s):
        freq_map[current_char] += 1

        while freq_map[current_char] > 1:
            left_char = s[left_bound]
            freq_map[left_char] -= 1
            left_bound += 1

        window_size = (right_bound - left_bound) + 1
        max_window_size = max(max_window_size, window_size)

    return max_window_size


def main():
    s = "abcad"
    print(linear_approach(s))


if __name__ == "__main__":
    main()
