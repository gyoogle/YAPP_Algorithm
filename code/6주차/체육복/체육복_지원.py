def solution(n, lost, reserve):
    lost_spare = []
    for i in lost:
        if i in reserve:
            reserve.remove(i)
        else:
            lost_spare.append(i)
    for i in lost_spare:
        if i-1 in reserve:
            reserve.remove(i-1)
            pass
        elif i+1 in reserve:
            reserve.remove(i+1)
            pass
        else:
            n -= 1  
    return n
