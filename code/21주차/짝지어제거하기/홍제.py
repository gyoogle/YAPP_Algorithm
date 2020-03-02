def solution(s):
    str2list = list(s)
    stack = []
    for i in str2list:
        if len(stack) == 0:
            stack.append(i)
        else:
            q = stack[-1]
            if q != i:
                stack.append(i)
            else:
                stack.pop()
    return 0 if stack else 1


if __name__ == '__main__':
    print(solution('baabaa'))
