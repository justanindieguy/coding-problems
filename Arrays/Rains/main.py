def trapped_water_quadratic(heights: list[int]):
    n = len(heights)
    if n < 3:
        return 0

    water_units = 0
    for i, num in enumerate(heights[1:-1], start=1):
        j = i
        left = 0
        while j >= 0:
            left = max(left, heights[j])
            j -= 1

        j = i
        right = 0
        while j < n:
            right = max(right, heights[j])
            j += 1

        water_units += min(left, right) - num

    return water_units


def trapped_water_linear(heights: list[int]):
    n = len(heights)
    if n < 3:
        return 0

    lefts = [0] * n
    rights = [0] * n
    lefts[0] = heights[0]
    rights[n - 1] = heights[n - 1]
    for i, num in enumerate(heights[1:], start=1):
        lefts[i] = max(lefts[i - 1], num)
        rights[n - i - 1] = max(rights[n - i], heights[n - i - 1])

    water_units = 0
    for i, num in enumerate(heights):
        water_units += min(lefts[i], rights[i]) - num

    return water_units


def main():
    heights = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    print(f"Water Units - Quadratic Time: {trapped_water_quadratic(heights)}")
    print(f"Water Units - Linear Time: {trapped_water_linear(heights)}")


if __name__ == "__main__":
    main()
