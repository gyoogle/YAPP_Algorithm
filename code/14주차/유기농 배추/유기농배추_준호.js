function solution(file){
    var fs = require('fs');
    var input_lines;
    if(file == undefined){
        input_lines = fs.readFileSync('/dev/stdin').toString().split('\n');
    }
    else{
        input_lines = fs.readFileSync(file).toString().split('\n');
    }

    var questions = parseInt(input_lines.shift());
    var answers = [];

    for(var q = 0 ; q < questions ; q ++){
        var info = input_lines.shift().split(/\s+/g).map(r => parseInt(r));
        var width = info[0];
        var height = info[1];
        var vegitableLen = info[2];

        var vegitables = input_lines.splice(0,vegitableLen).map(v => v.split(/\s+/g).map(v => parseInt(v)));
        var visited = new Array(width).fill(0).map(res => new Array(height).fill(0));;
        var map = new Array(width).fill(0).map(res => new Array(height).fill(0));;

        for(var i = 0 ; i < vegitableLen ; i ++){
            map[vegitables[i][0]][vegitables[i][1]] = 1;
        }

        var v =[[0,1],[0,-1],[1,0],[-1,0]];
    
    
        var work_queue = [];
    
        var answer = 0;
    
        for(var i = 0 ; i < width ; i ++){
            for(var j = 0 ; j < height ; j ++){
                
                if(visited[i][j] == 0 && map[i][j] == 1){
                    work_queue.push([i,j]);
                    visited[i][j] = 1;
    
                    while(work_queue.length > 0){
                        var pos = work_queue.shift();
                        
                        var x = pos[0];
                        var y = pos[1];
    
                        for(var k = 0 ; k < 4 ; k ++){
                            var next_x = x + v[k][0];
                            var next_y = y + v[k][1];
    
                            if(next_x >= 0 && next_x < width && next_y >= 0 && next_y < height &&
                                visited[next_x][next_y] == 0 && map[next_x][next_y] == 1){
                                    work_queue.push([next_x,next_y]);
                                    visited[next_x][next_y] = 1;
                                    
                                }
                        }
                    }                
                    answer ++;
                }
                else{
                    visited[i][j] = 1;
                }
    
    
            }
        }
    
        answers.push(answer)
    }



    

    return answers;
    
}
var answer = solution();
answer.forEach(v => console.log(v));