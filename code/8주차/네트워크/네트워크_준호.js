function solution(n, computers) {
   
    var nodeType = [1];
    var network = 1;
    var found = 1;
    
    var searchQueue = [0];
    
    for(let i = 1 ; i < n ; i ++){
        nodeType.push(0);
    }
    
    while(found != n){
        if(searchQueue.length == 0){
            
            network ++;
            
            for(let i = 0 ; i < n ; i ++){
                if(nodeType[i] == 0){
                    nodeType[i] = network;
                    searchQueue.push(i);
                    found ++;
                    
                    break;
                }
            }
        }
        
        let target = searchQueue.pop();
        
        for(let next = 0 ; next < computers[target].length ; next ++){
            if(computers[target][next] == 1)
                if(nodeType[next] == 0){
                    searchQueue.push(next);
                    nodeType[next] = network;
                    found ++;
                }
        }
        
    }
    
    return network;
}
