const dfs = (computers, visit)=>{
    
    for(let i = 0 ; i<computers.length; i++){
        
        if(computers[i] ===1){
            visit[i] = true
        }
    }
}
function solution(n, computers) {
    var answer = 0;
    const visit = []
    for(let i = 0 ; i<n; i++){
        visit.push(false)
    }
    for(let i = 0 ; i<n ;i++){
        if(!visit[i]){
            visit[i] = true
            answer++
        }
        
        for(let j = 0 ; j<n; j++){
            if(i===j) continue;
            if(computers[i][j] === 1 && !visit[j]){
                dfs(computers[j],visit)
            }    
        }
        
        
    }
    return answer;
}