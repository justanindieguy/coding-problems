def height_checker(heights: list[int]):
    sorted_heights = heights.copy()
    sorted_heights.sort()

    ans = 0
    for i, height in enumerate(sorted_heights):
        if heights[i] != height:
            ans += 1

    return ans


def main():
    heights = [1, 1, 4, 2, 1, 3]
    print(height_checker(heights))


if __name__ == "__main__":
    main()
