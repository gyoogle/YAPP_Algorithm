from functools import cmp_to_key
def compare(x, y):
    return (int(y + x) - int(x + y))

def solution(numbers): 
    if (all(v == 0 for v in numbers)):
        return "0"
    mylist = [str(n) for n in numbers]
    mylist = sorted(mylist, key=cmp_to_key(compare))
    return(''.join(mylist))
