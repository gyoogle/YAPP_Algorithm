'''
1 x: Enqueue element  into the end of the queue.
2: Dequeue the element at the front of the queue.
3: Print the element at the front of the queue.

10
1 42
2
1 14
3
1 28
3
1 60
1 78
2
2


10
1 76
1 33
2
1 23
1 97
1 21
3
3
1 74
3

출처: https://goodtogreate.tistory.com/entry/HackerRank-Queues-A-Tale-of-Two-Stacks [GOOD to GREAT]
'''


class MyQueue(object):
    def __init__(self):
        self.main = []
        self.sub = []

    def peek(self):
        while self.main:
            self.sub.append(self.main.pop())
        return self.sub[0]

    def pop(self):
        while self.main:
            self.sub.append(self.main.pop())
        self.sub.pop(0)

    def put(self, value):
        self.main.insert(0, value)


if __name__ == '__main__':
    queue = MyQueue()
    t = int(input())
    for line in range(t):
        print(queue.main)
        print(queue.sub)
        values = map(int, input().split())
        values = list(values)
        if values[0] == 1:
            queue.put(values[1])
        elif values[0] == 2:
            queue.pop()
        else:
            print(queue.peek())
