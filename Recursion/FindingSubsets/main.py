def get_subsets(subsets, s, o, start, end):
    if start == end:
        subsets.append(o)
        return

    # Take character at start
    o += s[start]
    get_subsets(subsets, s, o, start + 1, end)

    # Don't take it
    o = o[:-1]
    get_subsets(subsets, s, o, start + 1, end)


def main():
    subsets = []
    s = "abc"

    get_subsets(subsets, s, "", 0, len(s))
    print(subsets)


if __name__ == "__main__":
    main()
