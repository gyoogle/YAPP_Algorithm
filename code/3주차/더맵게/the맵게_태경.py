import heapq
def solution(scoville, K):
    if(len(scoville) == 1) :
        if(scoville[0] >= K) : return 0
        else : return -1
        
    answer = 0
    h = []
    for i in scoville:
        heapq.heappush(h,i)
    while(h[0] < K) :
        try:
            first = int(heapq.heappop(h))
            second = int(heapq.heappop(h))
            newScoville = first + second*2
            heapq.heappush(h, newScoville)
            answer += 1
        except IndexError :
                return -1
    
    if(answer == 0 ):
        return -1
    
    return answer