function solution(file){
    var fs = require('fs');
    var input_line;
    if(file == undefined){
        input_line = fs.readFileSync('/dev/stdin').toString().split('\n');
    }
    else{
        input_line = fs.readFileSync(file).toString().split('\n');
    }

    var N = parseInt(input_line.shift());

    var map = input_line.map(line => line.split(/\s+/g).map(number => parseInt(number)).filter(i => !isNaN(i)));

    let cur = [0,0,0];
    let next ;

    for(let i = 0; i < N ; i ++){
        next = [];

        next[0] = Math.min(cur[1] , cur[2]) + map[i][0];
        next[1] = Math.min(cur[0] , cur[2]) + map[i][1];
        next[2] = Math.min(cur[1] , cur[0]) + map[i][2];

        cur = next;
    }
    

    return Math.min(cur[0], cur[1],cur[2]);
}

console.log(solution());
