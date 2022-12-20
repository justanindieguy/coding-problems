def busy_life(activities: list[tuple[int]]):
    if len(activities) == 0:
        return 0

    activities.sort(key=lambda activity: activity[1])

    total = 1
    end = activities[0][1]
    for curr_activity in activities[1:]:
        if curr_activity[0] >= end:
            total += 1
            end = curr_activity[1]

    return total


def main():
    activities = [(7, 9), (0, 10), (4, 5), (8, 9), (4, 10), (5, 7)]
    print(busy_life(activities))


if __name__ == "__main__":
    main()
