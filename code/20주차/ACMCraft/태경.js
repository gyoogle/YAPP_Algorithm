const oneRound = (input, result)=>{
    const currentBulidCount = input[0].split(' ').map((el)=> parseInt(el));
    const buildTimes = input[1].split(' ').map((el)=> parseInt(el));
    buildTimes.unshift(0);
    const prevNeedTree = {}; //이전에 뭘지어야 하는지 알려주는 트리
    const nextTargetTree = {}; // 그건물을 지으면 다음건물 지을 수 있는 알려주는 트리
    const visited = new Array(currentBulidCount[0]+1).fill(false)
    /*트리 초기화 */
    for(let j = 1 ; j<=currentBulidCount[0]; j++){
        prevNeedTree[j] = [];
        nextTargetTree[j] = [];
    }
    let i = 0
    /* 트리 세팅 */
    for(; i<currentBulidCount[1]; i++){
        const treeItem = input[i+2].split(' ').map((el)=>parseInt(el));
        prevNeedTree[treeItem[1]] = [...prevNeedTree[treeItem[1]],treeItem[0]]
        nextTargetTree[treeItem[0]] = [...nextTargetTree[treeItem[0]], treeItem[1]]
    }
    const winTarget = parseInt(input[i+2])//이기기위한 최종 건물 번호
    
    // console.log(nextTargetTree)
    const queue = []

    for(let checkI = 1; checkI <= currentBulidCount[0]; checkI++){
        if(prevNeedTree[checkI].length == 0){
            for(let innerIndex = 0 ; innerIndex < nextTargetTree[checkI].length; innerIndex++){
                queue.push(nextTargetTree[checkI][innerIndex])
            }
        }
    }
    
    while(queue.length !== 0){  
        const nowTarget = queue.shift(); //큐에서 하나를 뺀다
        
        //뺀 큐의 번호를 가지고 이전에 지어야할 건물들의 번호를 살핀다.
        let worstTime = 0 ;
        
        for(let prevI = 0 ; prevI < prevNeedTree[nowTarget].length; prevI++){
            if(worstTime < buildTimes[prevNeedTree[nowTarget][prevI]]){
                worstTime = buildTimes[prevNeedTree[nowTarget][prevI]]
            }
        }
        //최악의 경우의 수를 buildTimes의 자신 번호에 더해서 셋팅한다
        if(visited[nowTarget] === false)
            buildTimes[nowTarget] += worstTime;
        visited[nowTarget] = true;
        //그리고 자신의 nextTargetTree번호를 queue뒤에다가 추가시킨다.
        for(let nextI = 0; nextI< nextTargetTree[nowTarget].length; nextI++){
            if(visited[nextTargetTree[nowTarget][nextI]] === false)
                queue.push(nextTargetTree[nowTarget][nextI])
        }
    }
    
    // 마지막으로 buildTimes[winTarget] 출력
    result.push(buildTimes[winTarget])
    return currentBulidCount[1]+3;
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
    const result = []
    while(input.length > 0){
        try{
            input.splice(0,oneRound(input, result));    
        }catch{
            break;
        }
    }
    const answer = result.map((el)=> el+"").join('\n');
    console.log(answer)
}

init('./input.txt')
