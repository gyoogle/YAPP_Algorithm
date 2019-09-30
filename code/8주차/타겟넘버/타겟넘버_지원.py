def dfs(index, total, numbers, target):    
    if index == len(numbers):
        if total == target: return 1
        else: return 0
    ret = dfs(index+1, total+numbers[index], numbers, target) + dfs(index+1, total-numbers[index], numbers, target)    
    return ret


def solution(numbers, target):
    answer = dfs(0, 0, numbers, target)
    return answer
