function solution(N) {
    var answer = 0;
    let first = 1, second = 1
    if(N === 0) return 0;
    if(N === 1) return 4;
    let last = first+second;
    for(let i = 0 ; i<N-1; i++){
        last = first + second
        first = second;
        second = last
    }
    answer = second*2 + first*2
    return answer;
}