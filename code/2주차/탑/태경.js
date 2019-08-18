function solution(heights) {
    const answer = []
    for(let i = 0 ; i<heights.length; i++){
        if(answer.length === 0 ){
            answer.push(0)
            continue
        }
        let j = i-1
        for(; j>=0 ;j--){
            if(heights[i] < heights[j]){
                answer.push(j+1)
                break;
            }
        }
        if(j === -1) answer.push(0)
    }
    return answer;
}