def print_subset(subset: list):
    for item in subset:
        if item != None:
            print(f"{item}, ", end="")
        else:
            print("", end="")

    print()


def generate_subsets(arr: list, subset: list, i: int):
    if i == len(arr):
        print_subset(subset)
    else:
        subset[i] = None
        generate_subsets(arr, subset, i + 1)
        subset[i] = arr[i]
        generate_subsets(arr, subset, i + 1)


def power_set(arr: list):
    subset = [None] * len(arr)
    generate_subsets(arr, subset, 0)


def main():
    arr = ["a", "b", "c"]
    power_set(arr)


if __name__ == "__main__":
    main()
