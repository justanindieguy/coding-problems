REPLACE_WITH = "%20"
SPACE_LEN = len(" ")


def get_all_occurrences(s: str, term: str):
    indexes = []
    idx = s.find(term)
    while idx != -1:
        indexes.append(idx)
        idx = s.find(term, idx + 1)

    return indexes


def get_additional_len(s: str):
    occurrences = get_all_occurrences(s, " ")
    return len(occurrences) * (len(REPLACE_WITH) - 1)


def resize_string(s: str):
    new_str = s[:]
    additional_len = get_additional_len(s)
    new_len = len(s) + additional_len

    return new_str.ljust(new_len)


def space20_quadratic(s: str):
    string_len = len(s)
    s = list(resize_string(s))

    diff = len(REPLACE_WITH) - SPACE_LEN
    i = 0
    while i < string_len:
        if s[i] == " ":
            for j, char in reversed(list(enumerate(s[i:string_len], start=i))):
                s[j + diff] = char

            for j, char in enumerate(REPLACE_WITH):
                s[i] = char
                i += 1

            string_len += diff
        else:
            i += 1

    return "".join(s)


def space20_linear(s: str):
    original_len = len(s)
    additional_len = get_additional_len(s)

    s = list(resize_string(s))
    diff = len(REPLACE_WITH) - SPACE_LEN
    for i, char in reversed(list(enumerate(s[:original_len]))):
        move_to = i + additional_len
        if char == " ":
            stop = move_to - diff
            j = move_to
            while j >= stop:
                s[j] = REPLACE_WITH[j - stop]
                j -= 1

            additional_len -= diff
        else:
            s[move_to] = s[i]

    return "".join(s)


def main():
    s = "hello world,  how are you?"
    print(s)
    print(space20_quadratic(s))
    print(space20_linear(s))


if __name__ == "__main__":
    main()
