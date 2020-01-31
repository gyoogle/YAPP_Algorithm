let cnt = 0;
const solution = (array = [], total, sum) =>{
    const copy = array.map((el)=> el);
    
    if(array.length === 0 ){
        
        if(total === sum) {
            cnt++
            return;
        }else{
            return
        }
    }
    if(sum > 20 || sum < 0){
        return
    }
    const nextValue = copy.pop()
    
    solution(copy, total, sum-nextValue)
    solution(copy, total, sum+nextValue);
    
    
}
function init(file){
    var fs = require('fs');
    var input
    if(file){
        input = fs.readFileSync(file).toString().split('\n');
    }else{
        input = fs.readFileSync('/dev/stdin').toString().split('\n');
    }
    
    const target = input[1].split(' ').map((el)=>{
        return parseInt(el)
    })
    const total = target.pop();
    solution(target, total, 0)
    console.log(cnt)   
}

init('./input.txt');