def solution(phone_book):
    answer = True
    
    hash_table = {}
    
    pos = 0
    
    for phone_number in phone_book :
        hash_table[phone_number] = pos
        pos = pos + 1
    
    pos = 0
    
    for phone_number in phone_book :
        for i in range(len(phone_number)) :
            if phone_number[0:i+1] in hash_table and hash_table[phone_number[0:i+1]] is not pos :
                return False
            
        pos = pos + 1
            
    return answer