def solution(budgets, M):
    answer = 0
    left = 0
    right = max(budgets)
    while left <= right:
        mid = (left+right)//2
        num = 0
        for b in budgets:
            if mid < b: 
                num+=mid
            else: 
                num+= b
        if num <= M and answer < mid:
            answer = mid
        elif num < M: 
            left = mid + 1
        else:
            right = mid - 1
    return answer
