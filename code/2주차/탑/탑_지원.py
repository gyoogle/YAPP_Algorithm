def solution(heights):
    answer = []
    for x in range(len(heights)):
        hit = None
        for y in range(x-1,-1,-1):
            if heights[x] < heights[y]:
                hit = y
                break
        if hit == None:
            answer.append(0)
        else:
            answer.append(hit+1)
    return answer
