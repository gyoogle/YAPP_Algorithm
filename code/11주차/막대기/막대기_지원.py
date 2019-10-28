def cut(stick):
    sum = 0
    cnt = 0
    size = 64
    while True:
        if sum == stick:
            return cnt
        if sum + size <= stick:
            sum += size
            size = size // 2
            cnt += 1
        else:
            size = size // 2
    return cnt

if __name__ == '__main__':
    print(cut(32))
