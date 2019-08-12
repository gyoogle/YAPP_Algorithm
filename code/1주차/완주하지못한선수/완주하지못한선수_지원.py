"""

1st: 
def solution(participant, completion):
    res = set(participant) - set(completion)
    if not res:
        for x in completion: 
            participant.remove(x)
        return participant[0]
    else: 
        return res.pop()

"""

def solution(participant, completion):
    res = set(participant) - set(completion)
    if not res:
        for player in completion:
            p1=completion.count(player)
            p2=participant.count(player)
            if(p1 != p2):
                return player
    else: 
        return res.pop()
