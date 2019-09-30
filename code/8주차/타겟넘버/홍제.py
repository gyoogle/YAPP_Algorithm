from itertools import product


def solution(numbers, target):
    answer = 0
    for case in product(['+', '-'], repeat=len(numbers)):
        i = sum([int(z[0] + str(z[1])) for z in zip(case, numbers)])
        if i == target:
            answer += 1
    return answer


if __name__ == "__main__":
    solution([1, 1, 1, 1, 1], 3)
