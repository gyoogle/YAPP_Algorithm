def solution(array, commands):
    num_com = len(commands)
    ans = []
    for i in range(num_com):
        first = commands[i][0]
        second = commands[i][1]
        idx = commands[i][2]
        cut = sorted(array[first-1:second])
        ans.append(cut[idx-1])
    return ans
