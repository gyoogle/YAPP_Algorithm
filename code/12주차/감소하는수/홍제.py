'''
음이 아닌 정수 X의 자릿수가 가장 큰 자릿수부터 작은 자릿수까지 감소한다면, 그 수를 감소하는 수라고 한다.
예를 들어, 321과 950은 감소하는 수지만, 322와 958은 아니다. N번째 감소하는 수를 출력하는 프로그램을 작성하시오.
0은 0번째 감소하는 수이고, 1은 1번째 감소하는 수이다. 만약 N번째 감소하는 수가 없다면 -1을 출력한다.
'''

base = list(range(10))


def solution(x):
    if x > 1022:
        return -1
    if x in base: return base[x]
    for i in base:
        for j in get_small_number(i):
            base.append(int(f'{i}{j}'))
            if len(base) - 1 == x:
                return base[x]


def get_small_number(i):
    return list(filter(lambda x: x < int(str(i)[-1]), range(10)))


if __name__ == "__main__":
    x = input()
    print(solution(int(x)))
