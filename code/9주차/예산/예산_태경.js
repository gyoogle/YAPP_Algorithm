function solution(budgets, M) {
    
    budgets.sort((a,b) => a-b);
    let length = budgets.length
    let start = 0 ;
    let answer = budgets[length-1]
    while(start <= answer){
        let sum = 0 ;
        let mid = parseInt((start+answer)/2)
        for(let el of budgets){
            if(el < mid){
                sum+=el;
            }else{
                sum+=mid;
            }
        }
        if(sum < M){
            start = mid+1
        } else{
            answer = mid -1
        }
    }
    return answer
}