function solution(file){
    var fs = require('fs');
    var input_line;
    if(file == undefined){
        input_line = fs.readFileSync('/dev/stdin').toString().split('\n');
    }
    else{
        input_line = fs.readFileSync(file).toString().split('\n');
    }

    var N = parseInt(input_line[0]);

    var dp = new Array(N +1);

    dp[0] = [1,0]; //dp[i][0] : (0,0) 인 경우, dp[i][1] : (0,1)/(1,0) 인경우
    
    for(let i = 1 ; i <= N ; i ++){
        dp[i] = [0,0];
        dp[i][0] = (dp[i-1][0] * 1 + dp[i-1][1] * 1) % 9901;
        dp[i][1] = (dp[i-1][0] * 2 + dp[i-1][1] * 1) % 9901;
    }
    
    

    return (dp[N][0] + dp[N][1])% 9901;
}

for(let i = 1 ; i <= 4 ; i ++)
console.log(solution('./ex' + i + '.txt'));
