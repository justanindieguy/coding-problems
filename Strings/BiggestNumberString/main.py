from functools import cmp_to_key


def compare(num_one: str, num_two: str):
    if num_one + num_two > num_two + num_one:
        return -1
    elif num_two + num_one > num_one + num_two:
        return 1
    else:
        return 0


def get_biggest_lexicographical_number(s: str):
    nums = s.split(",")
    nums.sort(key=cmp_to_key(compare))
    return "".join(nums)


def main():
    s = input()
    biggest_number = get_biggest_lexicographical_number(s)
    print(biggest_number)


if __name__ == "__main__":
    main()
