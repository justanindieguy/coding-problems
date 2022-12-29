def checkSubsequence(s_one: str, s_two: str):
    i = len(s_one) - 1
    j = len(s_two) - 1
    while i >= 0 and j >= 0:
        if s_two[j] == s_one[i]:
            i -= 1
            j -= 1
        else:
            i -= 1

    if j == -1:
        return True

    return False


def main():
    s_one = "codingminutes"
    s_two = "gits"
    result = "Yes" if checkSubsequence(s_one, s_two) else "No"
    print(result)


if __name__ == "__main__":
    main()
