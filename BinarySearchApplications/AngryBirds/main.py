def can_place_birds(birds: int, nests: list[int], separation: int):
    birds_with_place = 1
    last_location = nests[0]

    for current_location in nests[1:]:
        if current_location - last_location >= separation:
            birds_with_place += 1
            last_location = current_location

            if birds_with_place == birds:
                return True

    return False


def get_maximum_possible_distance(birds: int, nests: list[int]):
    n = len(nests)

    start, end = 0, nests[n - 1] - nests[0]
    ans = -1

    while start <= end:
        mid = (start + end) // 2
        can_place = can_place_birds(birds, nests, mid)

        if can_place:
            ans = mid
            start = mid + 1
        else:
            end = mid - 1

    return ans


def main():
    birds = 3
    nests = [1, 2, 4, 8, 9]

    nests.sort()

    print(get_maximum_possible_distance(birds, nests))


if __name__ == "__main__":
    main()
