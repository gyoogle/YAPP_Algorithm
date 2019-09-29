const dfs = (arr, sum,index,target,answer)=>{
    
    if(index === arr.length ){
        if(sum === target){
            answer[0] += 1
            return
        }
        return
    }
    
    const sum1 = sum - arr[index]
    const sum2 = sum + arr[index]
    dfs(arr, sum1, index+1, target, answer)
    dfs(arr, sum2, index+1, target, answer)    
}
function solution(numbers, target) {
    var answer = [0];
    
    dfs(numbers, 0, 0,target, answer)
    
    return answer[0];
}