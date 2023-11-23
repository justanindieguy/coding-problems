KEYPAD = {
    2: "ABC",
    3: "DEF",
    4: "GHI",
    5: "JKL",
    6: "MNO",
    7: "PQRS",
    8: "TUV",
    9: "WXYZ",
}


def print_keypad_output(input: str, output: str, i=0):
    if i == len(input):
        print(output)
        return

    current_digit = int(input[i])
    if current_digit == 0 or current_digit == 1:
        print_keypad_output(input, output, i + 1)

    digit_chars = KEYPAD[current_digit]
    for char in digit_chars:
        print_keypad_output(input, output + char, i + 1)

    return


def main():
    keypad_input = input()
    output = ""
    print_keypad_output(keypad_input, output)


if __name__ == "__main__":
    main()
