import sys

sys.stdin = open("2667.txt", "r")
n = int(input())
complex_map = [[int(line) for line in input()] for _ in range(n)]

dx = [0,0,-1,1]
dy = [-1,1,0,0]

complex = [0] * 100000
complex_num = 0

def search(i, j):
    complex_map[i][j] = 0
    complex[complex_num] += 1
    for x in range(4):
        nx = i + dx[x]
        ny = j + dy[x]
        if (nx >= 0 and nx < n and ny >=0 and ny < n):
            if (complex_map[nx][ny] == 1):
                search(nx, ny)

if __name__ == '__main__':
    for i in range(1,n):
        for j in range(1,n):
            if (complex_map[i][j] == 1):
                search(i, j)
                complex_num += 1

    complex = list(filter(lambda a: a != 0, complex))
    sorted_complex = sorted(complex)
    sorted_len = len(sorted_complex)

    print(sorted_len)
    for item in sorted_complex:
        print(item)
