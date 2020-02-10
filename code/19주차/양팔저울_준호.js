function solution(file){
    var fs = require('fs');
    var input_line;
    if(file == undefined){
        input_line = fs.readFileSync('/dev/stdin').toString().split('\n');
    }
    else{
        input_line = fs.readFileSync(file).toString().split('\n');
    }

    let W = parseInt(input_line[0]) ;
    let weight = input_line[1].split(/\s+/g).map(str => parseInt(str));
    let N = parseInt(input_line[2]);
    let marble = input_line[3].split(/\s+/g).map(str => parseInt(str));

    let MAGIC_NUMBER = 15000;

    let curDp = [], newDp;
    curDp[MAGIC_NUMBER + weight[0]] = 1;
    curDp[MAGIC_NUMBER - weight[0]] = 1;
    curDp[MAGIC_NUMBER] = 1;

    for(let i = 1 ; i < W ; i ++){

        let curWeight = weight[i];
        newDp = [];

        curDp.forEach((_,w) => {
            if(w + curWeight <= 40000 + MAGIC_NUMBER){
                newDp[w + curWeight] = 1;
            }
            if(w - curWeight >= 15000 - MAGIC_NUMBER){
                newDp[w - curWeight] = 1;
            }
            newDp[w] = 1;
        })

        MAGIC_NUMBER -= 500;

        curDp = newDp;
    }

    let answer = '';

    for(let i = 0 ; i < N ; i ++){
        if(curDp[marble[i] + 15000] == 1){
            answer += 'Y '
        }
        else{
            answer += 'N '
        }
    }

    answer.substr(0,answer.length-1)

    return answer;
}

console.log(solution('./ex1.txt'));
