
function solution(file){

    var dp;
    var map;
    var N ;
    var max = 1;
    var vec = [[-1,0],[1,0],[0,1],[0,-1]];

    function boundCheck(i,j){
        return 0 <= i && i < N && 0 <= j && j < N;
    }

    function DFS(i, j){

        let curMax = 0;

        for(let k = 0 ; k < 4 ; k ++){
            let next_i = i + vec[k][0] ;
            let next_j = j + vec[k][1];

            if(boundCheck(next_i,next_j) && map[i][j] < map[next_i][next_j]){

                let curTime = 0;

                if(dp[next_i][next_j] == 1){
                    curTime = DFS(next_i,next_j);
                }
                else{
                    curTime = dp[next_i][next_j];
                }

                if(curMax < curTime){
                    curMax = curTime;
                }
            }
        }

        dp[i][j] = curMax + 1;

        if(max < dp[i][j])
            max = dp[i][j];

        return dp[i][j];
    }

    var fs = require('fs');
    var input_line;
    if(file == undefined){
        input_line = fs.readFileSync('/dev/stdin').toString().split('\n');
    }
    else{
        input_line = fs.readFileSync(file).toString().split('\n');
    }

    N = parseInt(input_line.shift());

    dp = new Array(N).fill(null).map(i => new Array(N).fill(1));

    map = input_line.map(line => line.split(/\s+/g).map(txt => parseInt(txt)));

    for(let i = 0 ; i < N ; i ++){
        for(let j = 0 ; j < N ; j ++){
            if(dp[i][j] == 1){
                DFS(i,j);
            }
        }
    }


    return max ;
}

console.log(solution('./ex' + 1 + '.txt'));
