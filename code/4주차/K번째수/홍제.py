def solution(array, commands):
    return [sorted(array[command[0] - 1:command[1]])[command[2] - 1] for command in commands]


if __name__ == "__main__":
    print(solution([1, 5, 2, 6, 3, 7, 4], [[2, 5, 3], [4, 4, 1], [1, 7, 3]]))
