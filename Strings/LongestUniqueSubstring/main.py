def linear_approach(s: str):
    left_bound = 0
    max_length = 0
    char_map = {}

    for right_bound, current_char in enumerate(s):
        if current_char not in char_map or char_map[current_char] < left_bound:
            char_map[current_char] = right_bound
            max_length = max(max_length, (right_bound - left_bound) + 1)
        else:
            left_bound = char_map[current_char] + 1
            char_map[current_char] = right_bound

    return max_length


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
