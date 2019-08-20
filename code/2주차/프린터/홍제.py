from collections import deque


def solution_use_deque(priorities, location):
    answer = 0
    tmp = deque([(idx, prior) for idx, prior in enumerate(priorities)])
    base_tmp_location = tmp[location]

    while True:
        current_max = max([i[1] for i in tmp])
        if tmp[0][1] == current_max:
            answer += 1
            if tmp[0] == base_tmp_location:
                return answer
            tmp.popleft()
        else:
            tmp.append(tmp[0])
            tmp.popleft()

def solution_use_list(priorities, location):
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
    import time

    start = time.time()
    print(solution_use_deque([1, 1, 9, 1, 1, 1], 0))
    print("time :", time.time() - start)

    start = time.time()  # 시작 시간 저장
    print(solution_use_list([1, 1, 9, 1, 1, 1], 0))
    print("time :", time.time() - start)

    '''
    리스트의 원소가 적을떄에는 deque가 더 오래걸리는듯 하다.
    
    하지만 일반적으로는 앞에서 하나를 비우고 뒤에 있는 모든 데이터들을 한칸씩 앞으로 당기는 작업을 수반할때 
    가장 앞에있는 데이터를 끄집어 내는데 걸리는 시간 복잡도가 O(1)이 아닌 O(n) 되는 현상이 벌어진다.
    실제로도 퍼포먼스가 매우 떨어진다. 뒤집어서 pop을 하는게 빠를 정도이다.
    그래서 일반적으로 Python을 하는 사람들은 큐를 collections 모듈의 deque 클래스를 사용한다.
    그냥 구현되어 있는 것이 아니고, 아랫 단이 CPython으로 구현되어 있어서 퍼포먼스 차이가 말이 안될 정도로 차이가 난다.
    '''


