def solution(scoville, K):
    import heapq
    heapq.heapify(scoville)
    answer = 0

    s = heapq.heappop(scoville)
    while True:
        try:
            if s >= K:
                return answer
            t = heapq.heappop(scoville)
            s = heapq.heappushpop(scoville, s + t * 2)
            answer += 1
        except:
            return -1


if __name__ == "__main__":
    print(solution([1, 2, 3, 4, 5, 6], 7))
