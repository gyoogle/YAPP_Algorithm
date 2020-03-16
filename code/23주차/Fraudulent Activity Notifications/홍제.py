def get_median(is_even, _list, length):
    _list.sort()
    if is_even:
        q = int(length / 2)
        return (_list[q - 1] + _list[q]) / 2
    else:
        return _list[int(length / 2)]


def activityNotifications(expenditure, d):
    count = 0
    is_even = d % 2 == 0
    for idx, exp in enumerate(expenditure[d:]):
        median = get_median(is_even, expenditure[idx: idx + d], d)
        if exp >= median * 2:
            count += 1
    return count


if __name__ == '__main__':
    nd = input().split()

    n = int(nd[0])

    d = int(nd[1])

    expenditure = list(map(int, input().rstrip().split()))

    result = activityNotifications(expenditure, d)

    print(result)
