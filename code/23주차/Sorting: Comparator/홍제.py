from functools import cmp_to_key


class Player:
    def __init__(self, name, score):
        self.name = name
        self.score = score

    def __repr__(self):
        return repr(f"{self.name} {self.score}")

    @classmethod
    def comparator(cls, player_a, player_b):
        if player_a.score > player_b.score:
            return -1
        elif player_a.score == player_b.score:
            if player_a.name > player_b.name:
                return 1
            elif player_a.name == player_b.name:
                return 0
            elif player_a.name < player_b.name:
                return -1
        elif player_a.score < player_b.score:
            return 1


if __name__ == "__main__":
    result = []
    n = int(input())
    for i in range(n):
        name, score = input().split(' ')
        result.append(Player(name, int(score)))
    for i in sorted(result, key=cmp_to_key(Player.comparator)):
        print(f"{i.name} {i.score}")
