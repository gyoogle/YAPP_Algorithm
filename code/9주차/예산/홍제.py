def solution(budgets, M):
    if sum(budgets) <= M:
        return max(budgets)

    _max = max(budgets)
    _min = 1 if min(budgets) * len(budgets) > M else min(budgets)
    _mid = 0

    answer = 0
    while _min <= _max:
        _mid = (_min + _max) // 2
        if check_limit_money(_mid, budgets, M):
            _max = _mid - 1
        else:
            answer = _mid
            _min = _mid + 1

    return answer


def check_limit_money(limit_money, budgets, M):
    return sum([budget if budget < limit_money else limit_money for budget in budgets]) > M


if __name__ == "__main__":
    print(solution([5, 5, 5, 15, 25], 50))
