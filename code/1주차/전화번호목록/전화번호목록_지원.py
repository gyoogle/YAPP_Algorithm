def solution(phone_book):
    phone_book.sort()
    numbers = len(phone_book)
    for n in range(numbers):
        for i in range(n+1, numbers):
            if phone_book[n] in phone_book[i]:
                return False
    return True
