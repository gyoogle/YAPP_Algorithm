# 사이클제거

무방향 그래프의 사이클 탐지 기법 : union find algorithm

- https://jackpot53.tistory.com/92


단방향 그래프의 사이클 탐지 기법 : SCC-코사라주 알고리즘(Kosaraju's Algorithm)

- 컨셉설명 : https://ratsgo.github.io/data%20structure&algorithm/2017/11/23/SCC/

- 코사라주 알고리즘에 대한 예시 : https://wondy1128.tistory.com/130

union find algorithm으로 풀면 시간초과가 나옵니다.(union find algorithm은 어느 노드가 사이클을 일으키는지 정확하게 계산할 수 없음)

어떤 사이클이 나오는지 정확하게 계산해야합니다.
