function solution(clothes) {
    var answer = 1;
    
    var clothes_obj = {}
    
    for(var i = 0 ; i < clothes.length ; i ++){
        var type = clothes[i][1];
        
        if(clothes_obj[type] == undefined){
            clothes_obj[type] = 1;
        }
        else{
            clothes_obj[type] ++;
        }
    }
    
    var count_arr = Object.values(clothes_obj);
    
    for(var i = 0 ; i< count_arr.length ; i ++){
        answer = answer * (count_arr[i] + 1);
    }
    
    answer = answer - 1;
    
    return answer;
}