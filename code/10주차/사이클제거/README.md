# 사이클제거

무방향 그래프의 사이클 탐지 기법 : union find algorithm

- https://jackpot53.tistory.com/92


단방향 그래프의 사이클 탐지 기법 : SCC-코사라주 알고리즘(Kosaraju's Algorithm)

- 컨셉설명 : https://ratsgo.github.io/data%20structure&algorithm/2017/11/23/SCC/

- 코사라주 알고리즘에 대한 예시 : https://wondy1128.tistory.com/130


무(양)방향 그래프를 단방향 그래프로 변환한뒤 코사라주 알고리즘을 적용해도 무방하지만..

본 문제는 무방향 그래프가 주어져있으며, 어느 부분에서 순환이 일어나는지 찾는 것이 아니기 때문에

union find 알고리즘을 적용하는것이 더 빠르다

