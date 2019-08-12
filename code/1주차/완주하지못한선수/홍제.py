from collections import Counter


def solution(participant, completion):
    # A0 동명이인이 있을시 오류
    return list(filter(lambda part: part not in completion, participant))[0]

    # A1
    return list(Counter(participant) - Counter(completion))[0]

    # A2
    participant.sort()
    completion.sort()

    for part, comp in zip(participant, completion):
        if part != comp:
            return part
    return participant[-1]

    # A3
    answer = ''
    temp = 0
    dic = {}
    for part in participant:
        dic[hash(part)] = part
        temp += int(hash(part))
    for com in completion:
        temp -= hash(com)
    answer = dic[temp]

    return answer

if __name__ == "__main__":
    solution()