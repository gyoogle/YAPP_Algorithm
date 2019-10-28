def solution():
    X = int(input())
    a = [64]
    while sum(a) > X:
        b = a.pop()
        a.append(b // 2)
        a.append(b // 2)
        if sum(a[:-1]) >= X:
            a.pop()
        elif sum(a[:-1]) == X:
            break
    return len(a)

if __name__ == "__main__":
    print(solution())
