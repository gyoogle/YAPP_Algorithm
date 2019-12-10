'''
총 N개의 시험장이 있고, 각각의 시험장마다 응시자들이 있다. i번 시험장에 있는 응시자의 수는 Ai명이다.
감독관은 총감독관과 부감독관으로 두 종류가 있다. 총감독관은 한 방에서 감시할 수 있는 응시자의 수가 B명이고, 부감독관은 한 방에서 감시할 수 있는 응시자의 수가 C명이다.
각각의 시험장에 총감독관은 오직 1명만 있어야 하고, 부감독관은 여러 명 있어도 된다.
각 시험장마다 응시생들을 모두 감시해야 한다. 이때, 필요한 감독관 수의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 시험장의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다.
둘째 줄에는 각 시험장에 있는 응시자의 수 Ai (1 ≤ Ai ≤ 1,000,000)가 주어진다.
셋째 줄에는 B와 C가 주어진다. (1 ≤ B, C ≤ 1,000,000)

출력
각 시험장마다 응시생을 모두 감독하기 위해 필요한 감독관의 최소 수를 출력한다.

예제 입력 1
5
1000000 1000000 1000000 1000000 1000000
5 7
'''

from math import ceil

REQUIRED_MAINDIRECTOR = 0
REQUIRED_SUBDIRECTOR = 0


def solution(student, md, sd):
    global REQUIRED_MAINDIRECTOR
    global REQUIRED_SUBDIRECTOR

    remain_students = student - md
    REQUIRED_MAINDIRECTOR += 1
    if remain_students > 0:
        if remain_students <= sd:
            REQUIRED_SUBDIRECTOR += 1
        else:
            REQUIRED_SUBDIRECTOR += ceil(remain_students / sd)


if __name__ == "__main__":
    exam_site = int(input())
    students = map(int, input().split(' '))
    main_director, sub_director = list(map(int, input().split(' ')))
    for student in students:
        solution(student, main_director, sub_director)
    print(REQUIRED_MAINDIRECTOR + REQUIRED_SUBDIRECTOR)
