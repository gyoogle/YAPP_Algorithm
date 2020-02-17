const oneRound = (input)=>{
    const currentBulidCount = input[0].split(' ').map((el)=> parseInt(el));
    const buildTimes = input[1].split(' ').map((el)=> parseInt(el));
    const visited = new Array(currentBulidCount[0]+1).fill(false)
    buildTimes.unshift(0);
    const treeItems = {};
    for(let i = 1 ; i<=currentBulidCount[0]; i++){
        treeItems[i] = [];
    }
    let i = 0
    for(; i<currentBulidCount[1]; i++){
        const treeItem = input[i+2].split(' ').map((el)=>parseInt(el));
        treeItems[treeItem[1]] = [...treeItems[treeItem[1]],treeItem[0]]
    }
    const winTarget = parseInt(input[i+2])
    let currentNumber = winTarget;//winnerBuild
    let totalTimes = buildTimes[currentNumber];
    visited[winTarget] = true
    
    console.log(treeItems)
    console.log(treeItems[currentNumber])
    const queue = treeItems[currentNumber].map((el)=>el);
    while(queue.length !== 0){
        break;
    }
    // console.log(input)
    // console.log(buildTimes)
    // console.log(visited)
    return currentBulidCount[0]+3;
}

const init = (file)=>{
    var fs = require('fs');
    var input;
    if(file){
        input = fs.readFileSync(file).toString().split('\n');
    }else{
        input = fs.readFileSync('/dev/stdin').toString().split('\n');
    }
    input.shift();
    while(input.length > 0){
        input.splice(0,oneRound(input));
    }
}

init('./input.txt')


// {
//     "1" : [],
//     "2" : [1],
//     "3" : [1],
//     "4" ,
//     5 ,
//     6 : [3],
//     7 : [6,5],
//     8
// }