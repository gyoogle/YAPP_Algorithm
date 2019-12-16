function lineSimulator(prevLine,N){
    //start : 0

    var arr = prevLine.filter(number => number != 0);

    var L = arr.length ;

    for(var i = 0 ; i < L - 1 ; i ++){
        if(arr[i] == arr[i+1] ){
            arr[i] = arr[i] + arr[i+1];
            for(var j = i+1 ; j < L  - 1 ; j ++){
                arr[j] = arr[j+1];
            }

            L --;
        }
    }

    var newLine = new Array(N).fill(0);
    for(var i = 0 ; i < L ; i ++){
        newLine[i] = arr[i];
    }

    return newLine;
}

function simulator(puzzle,N,r){
    if(r == 0){
        var max = 0;
        for(var i = 0 ; i < N ; i ++){
            for(var j = 0 ; j < N ; j ++){
                if(max < puzzle[i][j])
                    max = puzzle[i][j]; 
            }
        }

        return max;
    }
    else{
        var max = 0;
        for(var m = 0 ; m < 4 ; m ++){
            var newPuzzle = move[m](puzzle,N);
            var res = simulator( newPuzzle, N, r-1)
            if(max < res){
                max = res;
            }
        }

        return max;
    }

}

var move = [leftMove, rightMove, topMove, bottomMove];

function leftMove(prevPuzzle, N){
    var puzzle = JSON.parse(JSON.stringify(prevPuzzle));
    
    var newPuzzle = [];

    for(var i = 0 ; i < N ; i ++){
        newPuzzle.push(lineSimulator(puzzle[i],N));
    }

    return newPuzzle;
}
function rightMove(prevPuzzle,N){
    var puzzle = JSON.parse(JSON.stringify(prevPuzzle));
    
    var newPuzzle = [];

    for(var i = 0 ; i < N ; i ++){
        newPuzzle.push(lineSimulator(puzzle[i].reverse(),N));
    }

    return newPuzzle;
}
function topMove(prevPuzzle,N){
    var puzzle = JSON.parse(JSON.stringify(prevPuzzle));
    
    var newPuzzle = [];

    for(var i = 0 ; i < N ; i ++){
        var prevLine = [];
        for(var j = 0 ; j < N ; j ++){
            prevLine.push(puzzle[j][i]);
        }
        newPuzzle.push(lineSimulator(prevLine,N));
    }

    return newPuzzle;
}
function bottomMove(prevPuzzle,N){
    var puzzle = JSON.parse(JSON.stringify(prevPuzzle));
    
    var newPuzzle = [];

    for(var i = 0 ; i < N ; i ++){
        var prevLine = [];
        for(var j = N -1 ; j >= 0 ; j --){
            prevLine.push(puzzle[j][i]);
        }
        newPuzzle.push(lineSimulator(prevLine,N));
    }

    return newPuzzle;
}

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

    var puzzle = input_line.map(line => line.split(/\s+/g).map(number => parseInt(number)).filter(i => !isNaN(i)));

    

    return simulator(puzzle,N, 5);
}

console.log(solution('./ex1.txt'));
