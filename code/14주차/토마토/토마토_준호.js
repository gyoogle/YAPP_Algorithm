function solution(file){
    var fs = require('fs');
    var input_lines;
    if(file == undefined){
        input_lines = fs.readFileSync('/dev/stdin').toString().split('\n');
    }
    else{
        input_lines = fs.readFileSync(file).toString().split('\n');
    }

    var work_queues = [[],[]];
    var cur_work_queue = work_queues[0]


    var info = input_lines.shift().split(/\s+/g).map(r => parseInt(r));
    var width = info[0];
    var height = info[1];

    var tomatos = input_lines.map(v => v.split(/\s+/g).map(v => parseInt(v)));

    var v =[[0,1],[0,-1],[1,0],[-1,0]];

    for(var i = 0 ; i < height ; i ++){
        for(var j = 0 ; j < width ; j ++){
            if(tomatos[i][j] == 1){
                cur_work_queue.push([i,j]);
            }
        }
    }

    var answer = -1;

    while(cur_work_queue.length > 0){
        answer ++;

        var next_work_queue = work_queues[(answer + 1) % 2];

        while(cur_work_queue.length > 0){   
            var pos = cur_work_queue.pop();     
            var y = pos[0];
            var x = pos[1];

            if(x -1 >= 0 &&  tomatos[y][x-1] == 0){
                    next_work_queue.push([y,x-1]);
                    tomatos[y][x-1] = 1;
            }
            if(x + 1 < width && 
                tomatos[y][x+1] == 0){
                    next_work_queue.push([y,x+1]);
                    tomatos[y][x+1] = 1;
            }
                
            if(y-1 >= 0 &&
                tomatos[y-1][x] == 0){
                    next_work_queue.push([y-1,x]);
                    tomatos[y-1][x] = 1;
            }
                
            if(y + 1 < height &&
                tomatos[y+1][x] == 0){
                    next_work_queue.push([y+1,x]);
                    tomatos[y+1][x] = 1;
            }
            
        }       

        cur_work_queue = next_work_queue;
    }
           

    for(var i = 0 ; i < height ; i ++){
        for(var j = 0 ; j < width ; j ++){
            if(tomatos[i][j] == 0){
                return -1;
            }
        }
    }
    

    return answer;
    
}

for(var i = 0 ; i < 10 ; i ++){
    var answer = solution('./ex'+ i + '.txt');
    console.log(i, answer)
}

var answer = solution('./ex3.txt');
console.log(answer)