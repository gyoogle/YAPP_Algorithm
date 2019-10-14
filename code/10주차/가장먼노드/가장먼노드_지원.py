def solution(n, edge):
    answer = 0
    adj_list = [[] for i in range(n+1)]
    for k, v in edge:
        adj_list[k].append(v)
        adj_list[v].append(k)
    queue = [1]
    distances = [0 for i in range(n+1)]
    visited = [False for i in range(n+1)]
    visited[1] = True
    while queue:
        i = queue.pop(0)
        for j in adj_list[i]:
            if not visited[j]:
                visited[j] = True
                distances[j] = distances[i] + 1
                queue.append(j)
    return distances.count(max(distances))
