function solution(file){
    var fs = require('fs');
    var input_line;
    if(file == undefined){
        input_line = fs.readFileSync('/dev/stdin').toString().split('\n');
    }
    else{
        input_line = fs.readFileSync(file).toString().split('\n');
    }

    var len = parseInt(input_line[0])
    var A = input_line[1].split(/\s+/).map(a => parseInt(a));
    var BC = input_line[2].split(/\s+/);
    var B = parseInt(BC[0]);
    var C = parseInt(BC[1]);

    var sum = 0;

    for(var i = 0 ; i < len ; i ++){
        A[i] -= B;

        sum += 1;

        if(A[i] > 0){
            sum += parseInt(A[i] / C) + (A[i]%C ? 1 : 0) ; 
        }
    }


    return sum;
}

console.log(solution());
