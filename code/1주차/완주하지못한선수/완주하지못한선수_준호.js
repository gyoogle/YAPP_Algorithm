function solution(participant, completion) {
    var answer = '';
    var part_obj = {};
    for(var i = 0 ; i < participant.length; i ++){
        var name =  participant[i]
        if(part_obj[name] == null){
            part_obj[name] = 1;
        }
        else{
            part_obj[name] ++;
        }
    }
    
    
    for(var i = 0 ; i < completion.length; i ++){
        var name = completion[i];
        part_obj[name] --;
        
        if(part_obj[name] == 0){
            delete part_obj[name]
        }
    }
    
    answer = Object.keys(part_obj)[0];
    
    return answer;
}