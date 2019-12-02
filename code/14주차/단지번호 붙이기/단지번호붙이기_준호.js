function solution(file){
    var fs = require('fs');
    var input_lines;
    if(file == undefined){
        input_lines = fs.readFileSync('/dev/stdin').toString().split('\n');
    }
    else{
        input_lines = fs.readFileSync(file).toString().split('\n');
    }

    var len = parseInt(input_lines.shift());
    var map = input_lines.map(input_line => input_line.split(/\s+/g)[0].split('').map(i => parseInt(i)));
    var visited = new Array(len).fill(0).map(res => new Array(len).fill(0));;


    var v =[[0,1],[0,-1],[1,0],[-1,0]];

    var answers = [];
    var work_queue = [];
    var answer ;

    for(var i = 0 ; i < len ; i ++){
        for(var j = 0 ; j < len ; j ++){
            
            if(visited[i][j] == 0 && map[i][j] == 1){
                answer = 0;
                work_queue.push([i,j]);
                visited[i][j] = 1;

                while(work_queue.length > 0){
                    var pos = work_queue.shift();
                    
                    var x = pos[0];
                    var y = pos[1];

                    answer ++;

                    for(var k = 0 ; k < 4 ; k ++){
                        var next_x = x + v[k][0];
                        var next_y = y + v[k][1];

                        if(next_x >= 0 && next_x < len && next_y >= 0 && next_y < len &&
                            visited[next_x][next_y] == 0 && map[next_x][next_y] == 1){
                                work_queue.push([next_x,next_y]);
                                visited[next_x][next_y] = 1;
                                
                            }
                    }
                }

                answers.push(answer);
            }
            else{
                visited[i][j] = 1;
            }

        }
    }

    return answers.sort((a,b)=> a-b);
    
}
var answer = solution('./ex1.txt');
console.log(answer.length);
answer.forEach(v => console.log(v));