def array_products_brute_force(arr: list[int]):
    products = [1] * len(arr)
    for i, n in enumerate(arr):
        product = 1
        for j, m in enumerate(arr):
            if i == j:
                continue

            product *= m

        products[i] = product

    return products


def array_products_precomputed(arr: list[int]):
    n = len(arr)

    if n == 1:
        return [0]

    temp = 1
    lefts = [1] * n
    for i, num in enumerate(arr):
        lefts[i] *= temp
        temp *= num

    temp = 1
    rights = [1] * n
    for i, num in reversed(list(enumerate(arr))):
        rights[i] *= temp
        temp *= num

    products = [1] * n
    for i, num in enumerate(arr):
        products[i] = lefts[i] * rights[i]

    return products


# Best Solution!
def array_products_precomputed_temp(arr: list[int]):
    n = len(arr)

    if n == 1:
        return [0]

    temp = 1
    products = [1] * n
    for i, num in enumerate(arr):
        products[i] = temp
        temp *= num

    temp = 1
    for i, num in reversed(list(enumerate(arr))):
        products[i] *= temp
        temp *= num

    return products


def main():
    arr = [1, 2, 3, 4, 5]
    print(array_products_brute_force(arr))
    print(array_products_precomputed(arr))
    print(array_products_precomputed_temp(arr))


if __name__ == "__main__":
    main()
