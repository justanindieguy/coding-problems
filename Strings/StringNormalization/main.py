def normalize(sentence: str):
    output = list(sentence)
    output[0] = output[0].upper()
    for i, char in enumerate(sentence[1:], start=1):
        space_before = sentence[i - 1] == " "
        if space_before:
            output[i] = char.upper()
        else:
            output[i] = char.lower()

    return "".join(output)


def main():
    input_sentence = input()
    print(normalize(input_sentence))


if __name__ == "__main__":
    main()
