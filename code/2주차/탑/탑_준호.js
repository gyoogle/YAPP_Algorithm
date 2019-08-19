function solution(heights) {
    
    var result = [];
    
    while(heights.length > 0){
        var cur = heights.pop();
        
        var i = heights.length;
        
        while(i > 0){
            if(heights[i - 1] > cur) 
                break;
            i --;
        }
        
        result.unshift(i);
    }
    
    return result;
}