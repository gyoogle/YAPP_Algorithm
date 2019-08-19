def solution(priorities, location):
    answer = 0
    tmp = [(idx, prior) for idx, prior in enumerate(priorities)]
    base_tmp_location = tmp[location]

    while True:
        current_max = max([i[1] for i in tmp])
        if tmp[0][1] == current_max:
            answer += 1
            if tmp[0] == base_tmp_location:
                return answer
            tmp.pop(0)
        else:
            tmp.append(tmp[0])
            tmp.pop(0)


if __name__ == "__main__":
    print(solution([2, 1, 3, 2], 2))
    print(solution([1, 1, 9, 1, 1, 1], 0))
