from heapq import *


def solution(n, works):
    if sum(works) <= n:
        return 0
    heap = []
    for work in works:
        heappush(heap, (-work, work))

    for i in range(n):
        max_node = heappop(heap)[1]
        max_node -= 1
        heappush(heap, (-max_node, max_node))

    return sum([j ** 2 for i, j in heap])


if __name__ == "__main__":
    print(solution(1, [2, 1, 2]))
