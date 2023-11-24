def get_permutations(o: list[str], chars: list[str], i=0):
    if i == len(chars):
        o.append("".join(chars))
        return

    for j, c in enumerate(chars[i:], start=i):
        chars[i], chars[j] = chars[j], chars[i]
        get_permutations(o, chars, i + 1)
        chars[i], chars[j] = chars[j], chars[i]


def get_sorted_permutations(s: str):
    permutations = []
    get_permutations(permutations, list(s))

    s = set(permutations)

    return sorted(list(s))


def main():
    for permutation in get_sorted_permutations(input()):
        print(permutation)


if __name__ == "__main__":
    main()
