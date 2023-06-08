def divide_among_k(l: list[int], k: int, min_coins: int):
    friends_covered = 0
    current_friend = 0

    for coins in l:
        if current_friend + coins >= min_coins:
            friends_covered += 1
            current_friend = 0
        else:
            current_friend += coins

    return friends_covered >= k


def binary_search_approach(l: list[int], k: int):
    start, end = min(l), sum(l)

    ans = 0
    while start <= end:
        mid = (start + end) // 2
        is_possible = divide_among_k(l, k, mid)

        if is_possible:
            start = mid + 1
            ans = mid
        else:
            end = mid - 1

    return ans


def main():
    coins = [10, 22, 40, 50]
    k = 3

    print(binary_search_approach(coins, k))


if __name__ == "__main__":
    main()
