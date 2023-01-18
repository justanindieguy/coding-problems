def main():
    x = int(input())

    """
    x & 1 will find out the last bit
    if last bit is 1 "x & 1" will return ...0001
    if last bit is 0 "x & 1" will return ...0000
    """
    if x & 1:
        print("Odd")
    else:
        print("Even")


if __name__ == "__main__":
    main()
