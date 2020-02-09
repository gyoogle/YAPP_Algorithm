function solution(file){
    var fs = require('fs');
    var input_line;
    if(file == undefined){
        input_line = fs.readFileSync('/dev/stdin').toString().split('\n');
    }
    else{
        input_line = fs.readFileSync(file).toString().split('\n');
    }

    let N = parseInt(input_line[0]) ;
    let data = input_line[1].split(/\s+/g).map(str => parseInt(str));

    let pre_dp = [];

    pre_dp[data[0]] = 1;

    for(let i = 1; i < N - 1 ; i ++){

        let cur_dp = [];
        let cur = data[i];

        //console.log('------', data[i])

        Object.keys(pre_dp).forEach(pre_str => {
            let pre = parseInt(pre_str);
            let number = pre_dp[pre];

            //console.log(pre,number)

            if(pre+cur <= 20)
                if(cur_dp[pre + cur] == undefined){
                    cur_dp[pre + cur] = number;
                }
                else{
                    cur_dp[pre + cur] += number
                }

            if(pre - cur >= 0)
                if(cur_dp[pre - cur] == undefined){
                    cur_dp[pre - cur] = number;
                }
                else{
                    cur_dp[pre - cur] += number
                }
        })

        pre_dp = cur_dp;
        //console.log(pre_dp)
    }

    let target = data[N - 1];
    //console.log(target)

    if(pre_dp[target] == undefined)
        return 0;
    return pre_dp[target];
}

console.log(solution('./ex1.txt'));
