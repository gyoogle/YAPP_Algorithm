from itertools import product


def solution(clothes):
    _dic = {}
    for cloth in clothes:
        if cloth[1] in _dic.keys():
            _dic[cloth[1]].append(cloth[0])
        else:
            _dic[cloth[1]] = [cloth[0]]

    # {'headgear': ['yellow_hat', 'green_turban'], 'eyewear': ['blue_sunglasses']}
    # product를 사용하면 리스트들의 곱집합을 뱉어준다.
    return len(list(product(*_dic.values())))
