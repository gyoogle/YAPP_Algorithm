'''
6 4
give me one grand today night
give one grand today
'''


def checkMagazine(magazine, note):
    dic = {}
    for _magazine in magazine:
        if _magazine in dic:
            dic[_magazine] += 1
        else:
            dic[_magazine] = 1

    for _note in note:
        if _note in dic and dic[_note] > 0:
            dic[_note] -= 1
        else:
            print('No')
            return
    print('Yes')


if __name__ == '__main__':
    mn = input().split()

    m = int(mn[0])

    n = int(mn[1])

    magazine = input().rstrip().split()

    note = input().rstrip().split()
    print(checkMagazine(magazine, note))
