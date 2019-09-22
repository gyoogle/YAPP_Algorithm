MEMO = {1: 1, 2: 1}


def solution(N):
    tiles = [fibonacci(i) for i in range(1, N + 1)]
    return 4 * tiles[-1] + 2 * tiles[-2]


def fibonacci(n):
    if n in MEMO:
        return MEMO[n]
    else:
        result = fibonacci(n - 1) + fibonacci(n - 2)
        MEMO[n] = result
        return result


if __name__ == "__main__":
    print(solution(5))
