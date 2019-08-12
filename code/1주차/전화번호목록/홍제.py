def solution(phone_book):
    answer = True
    for i in phone_book:
        for j in phone_book:
            if i == j:
                continue
            if j.startswith(i):
                return False

    return answer

if __name__ == "__main__":
    solution()
