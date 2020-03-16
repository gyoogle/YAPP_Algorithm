'''
7 50
1 12 5 111 200 1000 10
'''


def maximumToys(prices, k):
    prices.sort()
    total = 0
    count = 0
    for price in prices:
        total += price
        if total >= k:
            break
        count += 1
    return count


if __name__ == '__main__':
    nk = input().split()
    n = int(nk[0])
    k = int(nk[1])
    prices = list(map(int, input().rstrip().split()))
    result = maximumToys(prices, k)
    print(result)
