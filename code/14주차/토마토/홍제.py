'''
창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다.
보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다.
하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다.
대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다.
철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.

토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때,
며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라.
단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

입력
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N이 주어진다. M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다.
단, 2 ≤ M,N ≤ 1,000 이다. 둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다.
즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다. 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다.
정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.

5 5
-1 1 0 0 0
0 -1 -1 -1 0
0 -1 -1 -1 0
0 -1 -1 -1 0
0 0 0 0 0
'''
from collections import deque
from pprint import pprint

DX = [-1, 1, 0, 0]
DY = [0, 0, -1, 1]


def set_tomato(m, n):
    queue = deque()
    unripe_tomato = 0
    box = []
    for i in range(n):
        box.append(list(map(int, input().split(' '))))
        for j in range(m):
            if box[i][j] == 1:
                queue.append((i, j))
            elif box[i][j] == 0:
                unripe_tomato += 1
    return box, queue, unripe_tomato


def bfs(m, n, queue):
    global unripe_tomato
    global days
    # global box

    while queue:
        days += 1
        queue_len = len(queue)
        for i in range(queue_len):
            x, y = queue.popleft()
            for j in range(4):
                a, b = x + DX[j], y + DY[j]
                # a,b는 상하좌우를 게산한 좌표
                if 0 <= a < n and 0 <= b < m and box[a][b] == 0:
                    box[a][b] = 1
                    queue.append((a, b))
                    unripe_tomato -= 1

    return unripe_tomato


if __name__ == "__main__":
    days = 0
    m, n = map(int, input().split(' '))
    box, queue, unripe_tomato = set_tomato(m, n)
    if unripe_tomato == 0:
        print(0)
    else:
        bfs(m, n, queue)
        if unripe_tomato != 0:
            print(-1)
        else:
            print(days - 1)
