function solution(n, times) {
    var answer = null;
    const arr = times.map((e)=>e).sort((a,b)=>a-b)
    const target = arr.filter((e)=>arr[0] *n > e)
    
    let last = target[target.length-1] * n;
    let start = 1;
    let mid = 0;
    while(start<=last){
        mid = parseInt((start + last)/2);
        let cnt = 0;
        for(let i = 0; i<target.length ; i++){
            cnt+= parseInt(mid/target[i])
        }
        if(cnt < n){
            start = mid +1
        }else if (cnt>= n){
            last = mid -1
            if(answer === null){
                answer = mid
                continue;
            }
            answer = (answer < mid) ? answer: mid;
        }
    }
    return answer;
}