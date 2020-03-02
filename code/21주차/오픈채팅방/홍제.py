def solution(record):
    answer = []
    dic = {}
    tmp = []
    for rec in record:
        command = rec.split(' ')[0]
        if command == 'Enter':
            id = rec.split(' ')[1]
            nickname = rec.split(' ')[2]
            dic[id] = nickname
            tmp.append((id, '님이 들어왔습니다.'))
        elif command == 'Leave':
            id = rec.split(' ')[1]
            tmp.append((id, '님이 나갔습니다.'))
        elif command == 'Change':
            id = rec.split(' ')[1]
            nickname = rec.split(' ')[2]
            dic[id] = nickname

    for i in tmp:
        answer.append(f'{dic[i[0]]}{i[-1]}')
    return answer


if __name__ == '__main__':
    record = ["Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo",
              "Change uid4567 Ryan"]
    print(solution(record))
