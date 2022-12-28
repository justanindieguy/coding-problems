def is_subset_brute_force(s_one: str, s_two: str):
    if len(s_two) == 0:
        return True

    for char_one in s_two:
        present = False
        for char_two in s_one:
            if char_one == char_two:
                present = True
                break

        if not present:
            return False

    return True


def is_subset(s_one: str, s_two: str):
    return set(s_two).issubset(s_one)


def main():
    s_one = "codingminutes"
    s_two = "cines"
    result = "Yes" if is_subset(s_one, s_two) else "No"
    print(result)


if __name__ == "__main__":
    main()
