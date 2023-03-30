def sort_balls(balls: list[int]):
    n = len(balls)
    low, mid, high = 0, 0, n - 1

    while mid <= high:
        if balls[mid] == 0:
            balls[low], balls[mid] = balls[mid], balls[low]
            low += 1
            mid += 1
        elif balls[mid] == 1:
            mid += 1
        else:
            balls[mid], balls[high] = balls[high], balls[mid]
            high -= 1


def main():
    balls = [0, 0, 1, 2, 0, 1, 2, 0]
    sort_balls(balls)
    print(balls)


if __name__ == "__main__":
    main()
