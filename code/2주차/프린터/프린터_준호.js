function solution(priorities, location) {
    
    //---------- INIT -------------
    var pri_counter = Array(10).fill(0);
    var priorities_stack = [];
    
    var locations = Array(priorities.length);
    
    for(var i = 0 ; i < priorities.length; i ++){
        pri_counter[priorities[i]] ++;
        locations[i] = i;
    }
    
    for(var i = 1; i <= 9 ; i ++){
        if(pri_counter[i] > 0) priorities_stack.push(i);
    }
    
    //---------- START ------------
    
    var cur_priority = priorities_stack.pop();
    var count = 1;
    
    while(priorities.length > 0){
        var tar_pri = priorities.shift();
        var tar_loc = locations.shift();
        
        if(tar_pri < cur_priority){
            priorities.push(tar_pri);
            locations.push(tar_loc);
        }
        else{
            if(location == tar_loc){
                return count;
            }
            else{
                pri_counter[cur_priority] --;
                if(pri_counter[cur_priority] == 0){
                    cur_priority = priorities_stack.pop();
                }
                count ++;
            }
        }
        
        
    }
    
    var answer = 0;
    return answer;
}