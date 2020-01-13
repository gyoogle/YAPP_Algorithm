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
    var T= new Array(N+1), P = new Array(N+1);

    for(let i = 1 ; i <= N ; i ++){
        let [t, p] = input_line[i].split(/\s+/g);
        T[N - i + 1] = parseInt(t);
        P[N - i + 1] = parseInt(p);
    }

    var dp = new Array(N +1);

    dp[0] = 0;

    for(let i = 1 ; i <= N ; i ++){
        //현재 일자의 일을 고르지 않는 경우
        dp[i] = dp[i-1];

        //현재 일자의 일을 고를수 있다면
        if(i - T[i] >= 0){
            //현재 일자의 일을 고른경우가 고르지 않았을때보다 이득이라면
            if(dp[i] < dp[i - T[i]] + P[i]){
                dp[i] = dp[i - T[i]] + P[i];
            }
        }
        
    }

    
    

    return dp[N];
}

for(let i = 1 ; i <= 4 ; i ++)
console.log(solution('./ex' + i +'.txt'));
