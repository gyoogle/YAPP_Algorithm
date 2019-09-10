'''
map은 lazy evaluation(게으른 연산)을 진행하는데 계산 결과 값이 필요할때까지 계산을 늦추어서 메모리를 절약한다.
map 이 반환하는 것이 실제로는 list 자료형이 아니고 Iterator(반복가능한 객체)를 반환하는데, 이를 list로 변환해서 list 자료형으로 만드는 것.
Iterator는 next() 함수를 갖는 파이썬 객체로 꼭 메모리에 올릴 데이터만 올려서 메모리를 효율적으로 이용할 수 있는 파이썬의 대표적인 객체이다.
바로 list로 반환하는 것이 아니라 Iterator로 보다 상위의 객체를 리턴하는 것은,
다른 map 함수의 리턴값을 리스트가 아닌 다른 자료구조로 변환시킬 수도 있도록 하기 위해서이다.
'''


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
