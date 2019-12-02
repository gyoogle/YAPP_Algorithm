
const solution = (input)=>{
    input[0] = parseInt(input[0])
    const netWork = new Map()
    for(let i = 1 ; i<=input[0]; i++){
        console.log(input[i])
        const arr = input[i].split(' ')
        if(netWork.has(arr[0])){
            const tmp = [arr[1]]
            if(netWork.has(arr[1]))
                netWork.set(arr[0], [...netWork.get(arr[0]),[...netWork.get(arr[1]),arr[1]]])
            else{
                netWork.set(arr[0], [...netWork.get(arr[0]),arr[1]])
            }    
            
        }else{
            if(netWork.has(arr[1]))
                netWork.set(arr[0], [...netWork.get(arr[1]),arr[1]])
            else{
                netWork.set(arr[0], arr[1])
            }
        }
        if(netWork.has(arr[1])){
            if(netWork.has(arr[0]))
                netWork.set(arr[1], [...netWork.get(arr[1]),[...netWork.get(arr[0]),arr[0]]])
            else{
                netWork.set(arr[1], [...netWork.get(arr[1]),arr[0]])
            }
        }else{
            if(netWork.has(arr[0]))
                netWork.set(arr[1], [...netWork.get(arr[0]),arr[0]])
            else{
                netWork.set(arr[1], arr[0])
            }
            
        }
        const set = new Set()
        const leftFreinds = netWork.get(arr[0])
        const rightFreinds = netWork.get(arr[1])
        leftFreinds.map((el)=>{
            set.add(el)
        })
        rightFreinds.map((el)=>{
            set.add(el)
        })
        console.log(set)
    }
    console.log(netWork);
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
    solution(input)
    
}


init('./test.txt');