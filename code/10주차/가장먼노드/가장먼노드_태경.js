function solution(n, edge) {
    var answer = 0;
    
    const list = new Array(n);
    for(let i = 0 ; i<list.length; i++){
        list[i] = new Array(n);
    }
    
    for(let i = 0; i < edge.length; i++){
        const first = edge[i][0] -1;
        const second = edge[i][1] -1;
        list[first][second] = 1;
        list[second][first] = 1;
    }
    
    const path = new Array(n).fill(null)
    
    let level = 0 ; 
    let q = [0]
    path[0] = 0;
    while(q.length !== 0){
       let tmp = []
       
       while(q.length !==0){
           const now = q.shift()
           for(let j = 0; j<list.length; j++){
                if(list[now][j] === 1 && path[j] === null){
                    tmp.push(j)
                    path[j] = level
                }    
           }if(tmp.length ===0 && q.length ===0) break;   
       }
       level++;
       q=tmp
    }
    
    let max = 0 ;
    for(let i = 0 ; i < path.length; i++){
        if(max < path[i]){
            max = path[i]
        }
    }
    
    for(let i = 0 ; i<path.length; i++){
        if(max === path[i]) answer++
    }
    return answer;
}

//visited 사용해보자!