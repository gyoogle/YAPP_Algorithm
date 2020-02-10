function solution(file){
    var fs = require('fs');
    var input_line;
    if(file == undefined){
        input_line = fs.readFileSync('/dev/stdin').toString().split('\n');
    }
    else{
        input_line = fs.readFileSync(file).toString().split('\n');
    }

    let [N, K] = input_line[0].split(/\s+/g).map(str => parseInt(str));

    let curDp = [], newDp;

    let MIN = 0; 

    curDp[N] = 1;

    for(let i = 0 ; i < K  ; i ++){

        newDp = [];

        for(let j = 0 ; j <= N ; j ++){
            curDp.forEach((_, n) => {
                if(n - j >= MIN){
                    if(newDp[n - j] ==undefined)
                        newDp[n - j] = curDp[n];
                    else
                        newDp[n - j] += curDp[n]; 
                }

            })
        }

        curDp = newDp;

        curDp.forEach((v,i) => {
            curDp[i] = v % 1000000000;
        })
    }

    //console.log(Object.keys(curDp), Object.values(curDp))

    return curDp[0];
}

console.log(solution('./ex1.txt'));
