function * generator(){
    while(1){
        yield 1;
    }
}
const solution = (arr)=>{
    let cnt = 0;
    for(let i = 0 ; i<arr[0]; i++){
        for(let j = 0 ; j<arr[1]; j++){
            cnt+= generator().next().value;
        }
    }    
    return cnt-1;
}
function init(file){
    var fs = require('fs');
    var input
    if(file){
        input = fs.readFileSync(file).toString().split('\n');
    }else{
        input = fs.readFileSync('/dev/stdin').toString().split('\n');
    }
    const arr = input.toString().split(' ').map((e)=> parseInt(e))
    const answer = solution(arr)
    
    
    console.log(answer)
}


init('./test.txt');
