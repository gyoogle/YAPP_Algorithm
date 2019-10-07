//시간 초과나요. 안되는 코드.

function solution(n, times) {
    var answer = 0;
    var len = times.length
    
    var wait = JSON.parse(JSON.stringify(times));

    for(let i = len; i < n ; i ++){
        
        let complete = 1000000000;
        
        
        let target = 0;
        
        for(let j = 0 ; j < len ; j ++){
            if(complete > wait[j] + times[j])
            {
                complete = wait[j] + times[j];
                target = j;
            }
        }
        
        let remain = wait[target];
        
        for(let j = 0 ; j < len ; j ++){
            wait[j] = wait[j] - remain > 0 ? wait[j] - remain : 0;
        }
        
        wait[target] = times[target];
        
        answer += remain;
        

    }
    
    var remain = 0;
    
    for(let i = 0 ; i < len ; i ++){
        if(wait[i] > remain)
            remain = wait[i];
    }
    
    answer += remain;
    
    return answer;
}
