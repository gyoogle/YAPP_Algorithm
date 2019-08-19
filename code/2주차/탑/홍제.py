def solution(heights):
    answer = []
    for idx, i in enumerate(reversed(heights)):
        for idx2, j in enumerate(reversed(heights[:len(heights) - idx - 1])):
            if i < j:
                answer.insert(0, len(heights[:len(heights) - idx - 1]) - idx2)
                break
        else:
            # for문이 끝나고 중간에 break가 되지 않으면 실행되는 for - else 이다.
            answer.insert(0, 0)

    return answer


if __name__ == "__main__":
    print(solution([1, 5, 3, 6, 7, 6, 5]))
