from collections import defaultdict


def binary_search(cost, k):
    mid = int(len(cost) / 2)
    start = 0
    end = len(cost) - 1
    while start <= end:
        if cost[mid] == k:
            return mid
        elif cost[mid] > k:
            end = mid - 1
        else:
            start = mid + 1
        mid = int((start + end) / 2)
    return None


def what_flavors(cost, money):
    result = []
    dic = defaultdict(list)
    for idx, i in enumerate(cost):
        dic[i].append(idx)
        target = money - i
        if target > 0 and dic.get(target):
            for j in dic[target]:
                if j != idx:
                    result.append(idx + 1)
                    result.append(j + 1)
                    print(' '.join(list(map(str, sorted(result)))))
                    return None


if __name__ == '__main__':
    t = int(input())
    for t_itr in range(t):
        money = int(input())
        n = int(input())
        cost = list(map(int, input().rstrip().split()))
        what_flavors(cost, money)
