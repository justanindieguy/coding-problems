def linear_approach(nums: list[int], target: int):
    traversed = {}

    for i, num in enumerate(nums):
        complement = target - num

        if complement in traversed:
            return (i, traversed[complement])

        traversed[num] = i

    return (-1, -1)


def main():
    target = 9
    nums = [2, 7, 11, 15]

    print(linear_approach(nums, target))


if __name__ == "__main__":
    main()
