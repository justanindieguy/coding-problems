def get_rows():
    rows = []
    for i in range(int(input())):
        rows.append(input())

    return rows


def get_params():
    [key, reverse, ordering] = input().split(" ")

    if reverse == "true":
        reverse = True
    else:
        reverse = False

    parse = False
    if ordering == "numeric":
        parse = True

    return [int(key), reverse, parse]


def get_rows_with_keys(column_number: int, parse: bool, rows: list[str]):
    rows_n_keys = []
    for row in rows:
        keys = row.split(" ")
        selected_key = keys[column_number - 1]

        if parse:
            selected_key = int(selected_key)

        rows_n_keys.append((row, selected_key))

    return rows_n_keys


def main():
    rows: list[str] = get_rows()
    [key, reverse, parse] = get_params()

    # Sort the keys based on params entered by user.
    rows_with_keys = get_rows_with_keys(key, parse, rows)
    rows_with_keys.sort(key=lambda r: r[1], reverse=reverse)

    for row, key in rows_with_keys:
        print(row)


if __name__ == "__main__":
    main()
