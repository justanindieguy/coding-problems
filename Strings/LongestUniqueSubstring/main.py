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


def set_approach(s: str):
    left_bound = 0
    max_length = 0

    char_set: set[str] = set()

    for right_bound, current_char in enumerate(s):
        if current_char not in char_set:
            char_set.add(current_char)
            max_length = max(max_length, (right_bound - left_bound) + 1)
        else:
            while current_char in char_set:
                char_set.discard(s[left_bound])
                left_bound += 1

            char_set.add(current_char)

    return max_length


def main():
    s = "abcad"
    print(linear_approach(s))
    print(set_approach(s))


if __name__ == "__main__":
    main()
