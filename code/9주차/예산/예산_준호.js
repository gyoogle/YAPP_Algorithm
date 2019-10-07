function solution(budgets, M) {
    var cur = parseInt(M/2);

    var change = parseInt(M/4);
    
    var total = 0;
    var answer = 1;
    var time = 1000000;
    var max = 0;
    
    for(var i = 0 ; i < budgets.length ;  i++){
        if(budgets[i] > max){
            max = budgets[i];
        }
    }
    
    while(true){
        
        total = 0;
        
        
        for(var i = 0 ; i < budgets.length ; i++){
            total += (budgets[i] > cur ? cur : budgets[i]);
        }
        
        
        if(total  > M){
            cur -= change;
        }
        else{
            
            if(answer < cur){
                answer = cur;
            }
            
            cur += change;
            
                
        }
        
        time -= 1;
        
        if(parseInt(change / 2)  == 1){
            time = change;
        }
        
        change = parseInt(change / 2);
        
        if(time == -1)
            break;
            
    }
    
    return answer> max ? max : answer;
}
