const solution= (student =[] , teacher = [])=>{
    let cnt = 0;
    for(let i = 0; i<student.length; i++){
        cnt++
        let tmp = student[i] - teacher[0]
        if(teacher[1] === 0){
            continue;
        }
        if(tmp % teacher[1] ===0){
            cnt+=tmp/teacher[1]
        }else{
            cnt+= parseInt(tmp/teacher[1]) + 1
        }
    }
    console.log(cnt);
}

function init(file){
    var fs = require('fs');
    var input
    if(file){
        input = fs.readFileSync(file).toString().split('\n');
    }else{
        input = fs.readFileSync('/dev/stdin').toString().split('\n');
    }
    input.shift();
    const data = input[0].split(' ').map((el)=> parseInt(el))
    const human = input[1].split(' ').map((el)=> parseInt(el))
    solution(data, human)
    
}


init('./tmp.txt');