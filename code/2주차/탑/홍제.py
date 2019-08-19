def solution(heights):
    answer = []
    for idx, i in enumerate(reversed(heights)):
        for idx2, j in enumerate(reversed(heights[:len(heights) - idx - 1])):
            if i < j:
                answer.insert(0, len(heights[:len(heights) - idx - 1]) - idx2)
                break
        else:
            answer.insert(0, 0)

    return answer


if __name__ == "__main__":
    print(solution([1, 5, 3, 6, 7, 6, 5]))
