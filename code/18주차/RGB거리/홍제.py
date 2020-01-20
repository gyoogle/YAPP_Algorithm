def solution(payments):
    d = [[0, 0, 0] for _ in range(N + 1)]
    for i in range(1, N + 1):
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + payments[i - 1][0]
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + payments[i - 1][1]
        d[i][2] = min(d[i - 1][0], d[i - 1][1]) + payments[i - 1][2]

    return min(d[N])


if __name__ == "__main__":
    N = int(input())
    payments = []
    for i in range(N):
        payments.append(list(map(int, input().split(' '))))
    print(solution(payments))
