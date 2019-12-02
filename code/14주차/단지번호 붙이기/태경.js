const dfs = (isArr, initArr,i,j, cnt)=>{
    let queue = []
    isArr[i][j] = 1;
    queue.push([i,j])
    cnt++;
    const dx = [-1, 1, 0, 0]
    const dy = [0, 0, -1, 1]
    while(queue.length !== 0){
        const [currentX, currentY] = queue.shift()
        for(let i = 0; i<4; i++){
            const nextX = currentX + dx[i]
            const nextY = currentY + dy[i]

            if(nextX >= 0 && nextX <initArr.length && nextY >=0 && nextY <initArr.length){
                if(initArr[nextX][nextY] ===1 && isArr[nextX][nextY] === 0){
                    isArr[nextX][nextY] = 1;
                    cnt++;
                    queue.push([nextX,nextY])
                }
            }
        }
    }
    return cnt;
        
}
const solution = (initArr)=>{
    
    const isArr = new Array(initArr.length)
    for(let i = 0 ; i<initArr.length; i++){
        isArr[i] = new Array(initArr[i].length)
        for(let j = 0 ; j<initArr.length; j++){
            isArr[i][j] = 0;
        }
    }
    
    const answers =[]
    for(let i = 0 ; i<initArr.length; i++){
        for(let j = 0; j<initArr[i].length; j++){
            if(initArr[i][j] === 1&& isArr[i][j] ===0){
                answers.push(dfs(isArr, initArr,i,j,0))
                
            }
        }
    }
    console.log(answers.length);
    for(let i =0 ; i< answers.length; i++){
        console.log(answers[i])
    }
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
    const datas =[]
    for(let i = 0 ; i<input.length; i++){
        datas.push(input[i].split('')) 
    }
    for(let i = 0 ; i<datas.length; i++){
        for(let j = 0; j<datas[i].length; j++){
            datas[i][j] = parseInt(datas[i][j])
        }
    }    
    solution(datas)
    
}


init('./test.txt');