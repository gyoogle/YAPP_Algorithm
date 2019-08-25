import heapq

def solution(scoville, K):
    i = 0
    if len(scoville) > 1:
        heapq.heapify(scoville)
        answer = 0
        if scoville[0] > K:
            pass
        else:
            while K > scoville[0]:
                answer = heapq.heappop(scoville)
                answer += heapq.heappop(scoville) * 2
                heapq.heappush(scoville, answer)
                i += 1
    return i
