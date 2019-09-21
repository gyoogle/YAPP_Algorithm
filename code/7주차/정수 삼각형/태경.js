function solution(triangle) {
    var answer = triangle[0][0];
    for(let i = 1; i<triangle.length; i++){
        for(let j = 0 ; j<triangle[i].length; j++){
            if(j=== 0) {
                triangle[i][j] += triangle[i-1][0] 
                continue
            }
            triangle[i][j] += triangle[i-1][j-1] < triangle[i-1][j] ?  triangle[i-1][j] : triangle[i-1][j-1]
        }
    }
    for(let i = 0 ; i<triangle.length; i++){
        for(let j = 0 ; j<triangle[i].length; j++){
            answer = answer > triangle[i][j] ? answer : triangle[i][j]
        }
    }
    return answer;
}

function binary(arr,tot,max, i,j){
    tot+=arr[i][j]
    max[0] = tot < max[0] ? max[0] : tot
    if(i === arr.length-1){
        return
    }
    else{
        binary(arr, tot, max, i+1, j)
        binary(arr, tot, max, i+1, j+1)  
    }
}