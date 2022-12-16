def count_min_swaps(arr: list[int]):
    ans = 0
    n = len(arr)

    # Store the current indices.
    values_and_old_indexes = []
    for i, num in enumerate(arr):
        values_and_old_indexes.append((num, i))

    # Know the actual positions of elements (sorting by value)
    values_and_old_indexes.sort(key=lambda t: t[0])

    visited = [False] * n
    for i, num in enumerate(arr):
        # If element is visited or element is in the right position.
        old_position = values_and_old_indexes[i][1]
        if visited[i] or old_position == i:
            continue

        # Visiting the element (index) for the first time.
        node = i
        cycle_length = 0
        while not visited[node]:
            visited[node] = True
            next_node = values_and_old_indexes[node][1]
            node = next_node
            cycle_length += 1

        ans += (cycle_length - 1)

    return ans


def main():
    arr = [10, 11, 5, 4, 3, 2, 1]
    print(f"Minimum Swaps: {count_min_swaps(arr)}")


if __name__ == "__main__":
    main()
