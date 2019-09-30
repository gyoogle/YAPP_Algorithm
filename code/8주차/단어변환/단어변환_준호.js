function solution(begin, target, words) {    
    words.unshift(begin);
    
    var workQueue = [[0, 0]]; // [(node, time), ...]
    
    var visited = [];
    var graph = [];
    
    for(let i = 0 ; i < words.length ; i ++){
        
        var edge = [];
        
        for(let j = 0 ; j < words.length ; j ++){
            
            let time = 0;
            
            for(let w = 0 ; w < words[i].length ; w ++){
                if(words[i][w] != words[j][w])
                    time ++;
            }
            
            edge.push(time <= 1 ? 1 : 0);
        }
        
        graph.push(edge);
        visited.push(0);
    }
    
    visited[0] = 1;
        
    
    while(workQueue.length > 0){
        let curWork = workQueue.shift();
        let node = curWork[0];
        let time = curWork[1];
        
        let curEdge = graph[node];
        
        if(words[node] == target){
            return time;
        }
        
        
        for(let i = 0 ; i < curEdge.length ; i ++){
            if(visited[i] == 0 && curEdge[i] == 1){
                workQueue.push([i, time + 1]);
                visited[i] = 1;
            }
        }
    }
        
    return 0;
}
