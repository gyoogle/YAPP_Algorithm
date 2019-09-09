def solution(answers):
    answer = []
    score = [0,0,0,0]
    person1 = [1,2,3,4,5]
    person2 = [2,1,2,3,2,4,2,5]
    person3 = [3,3,1,1,2,2,4,4,5,5]
    for i in range(len(answers)):
        if answers[i] == person1[i%5]:
            score[1] += 1
        if answers[i] == person2[i%8]:
            score[2] += 1
        if answers[i] == person3[i%10]:
            score[3] += 1
            
    for i in range(len(score)):
        if score[i] == max(score):
            answer.append(i)
    return answer
