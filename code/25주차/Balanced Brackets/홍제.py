#!/bin/python3

# Complete the isBalanced function below.
def isBalanced(s):
    stack = []
    for i in s:
        if not stack:
            stack.append(i)
        else:
            if stack[-1] == '(' and i == ')':
                stack.pop()
            elif stack[-1] == '[' and i == ']':
                stack.pop()
            elif stack[-1] == '{' and i == '}':
                stack.pop()
            else:
                stack.append(i)
    return 'NO' if stack else 'YES'


if __name__ == '__main__':
    t = int(input())
    for t_itr in range(t):
        s = input()
        result = isBalanced(s)
        print(result)
