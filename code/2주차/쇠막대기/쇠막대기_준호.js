function solution(arrangement) {
    var answer = 0;    
    
    arrangement = arrangement.replace(/\(\)/g,'1');
    
    var stack = [0];
    
    for(var i = 0 ; i < arrangement.length ; i ++){
        if(arrangement[i] == '('){
            stack.push(0);
        }
        else if(arrangement[i] == ')'){
            var count = stack.pop();
            answer += count +1;
        }
        else{
            for(var j = 0 ; j < stack.length ; j ++){
                stack[j] ++;
            }
        }
    }
    
    return answer;
}