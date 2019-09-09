import math


def solution(answer):
    dic = {}
    dic['first'] = [1, 2, 3, 4, 5]
    dic['second'] = [2, 1, 2, 3, 2, 4, 2, 5]
    dic['third'] = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]

    dic = {k: (v * math.ceil(len(answer) / len(v)))[:len(answer)] for k, v in dic.items()}

    for k, v in dic.items():
        dic[k] = check_answer(v, answer)

    max_answer = max(dic, key=dic.get)

    return list(set([{'first': 1, 'second': 2, 'third': 3}[k] for k, v in dic.items() if dic[max_answer] == v]))


def check_answer(li, s):
    q = 0
    for i in range(len(s)):
        if s[i] == li[i]:
            q += 1
    return q


if __name__ == "__main__":
    print(solution([1, 3, 2, 4, 2]))
