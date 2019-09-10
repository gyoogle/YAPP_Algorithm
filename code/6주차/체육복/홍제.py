def solution(n, lost, reserve):
    intersection = list(set(lost).intersection(reserve))
    lost = list(filter(lambda lo: lo not in intersection, lost))
    reserve = list(filter(lambda re: re not in intersection, reserve))

    saved_student = list(range(1, n + 1))
    for i in lost:
        saved_student.remove(i)

    for i in lost:
        if find_front_num(i, reserve):
            saved_student.append(i)
            reserve.remove(i - 1)
        elif find_rear_num(i, reserve):
            saved_student.append(i)
            reserve.remove(i + 1)

    return len(saved_student)


def find_front_num(i, _list):
    return i - 1 in _list


def find_rear_num(i, _list):
    return i + 1 in _list


if __name__ == "__main__":
    solution(5, [2, 4], [1, 3, 5])
