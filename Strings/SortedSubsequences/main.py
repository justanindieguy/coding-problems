from functools import cmp_to_key


def compare(s_one: str, s_two: str):
    if len(s_one) == len(s_two):
        if s_one < s_two:
            return -1

        if s_one > s_two:
            return 1

        return 0

    return len(s_one) - len(s_two)


def generate_subsequences(s: str, output: str, subsequences: list[str]):
    # Base Case
    if len(s) == 0:
        subsequences.append(output)
        return

    # Recursive Case
    ch = s[0]

    # Take
    generate_subsequences(s[1:], output + ch, subsequences)

    # Do not take
    generate_subsequences(s[1:], output, subsequences)


def main():
    s = input()
    subsequences = []

    generate_subsequences(s, "", subsequences)
    subsequences.sort(key=cmp_to_key(compare))

    for sub in subsequences:
        print(sub)


if __name__ == "__main__":
    main()
