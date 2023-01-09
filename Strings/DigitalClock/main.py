def apply_time_format(n: int):
    if n < 10:
        return f"0{n}"

    return f"{n}"


def convert_to_digital_time(raw_minutes: str):
    hours = raw_minutes // 60
    minutes = apply_time_format(raw_minutes % 60)
    return f"{hours}:{minutes}"


def main():
    raw_minutes = int(input())
    print(convert_to_digital_time(raw_minutes))


if __name__ == "__main__":
    main()
