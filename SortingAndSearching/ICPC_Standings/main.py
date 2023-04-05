def badness(teams: list[tuple[str, int]]):
    n = len(teams)
    cnt = [0] * (n + 1)

    for team, preferred_rank in teams:
        cnt[preferred_rank] += 1

    pos, ans = 1, 0
    for i in range(1, n + 1):
        while cnt[i]:
            ans += abs(pos - i)
            cnt[i] -= 1
            pos += 1

    return ans


def main():
    teams = [
        ("WinOrBooze", 1),
        ("BallOfDuty", 2),
        ("WhoKnows", 2),
        ("BholeChature", 1),
        ("DCECoders", 5),
        ("StrangeCase", 7),
        ("WhoKnows", 7),
    ]

    print(badness(teams))


if __name__ == "__main__":
    main()
