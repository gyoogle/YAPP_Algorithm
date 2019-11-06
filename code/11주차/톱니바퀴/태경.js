
const leftRotate = (arr)=>{
    arr.push(arr.shift())
}
const rightRotate = (arr)=>{
    arr.unshift(arr.pop())
}

const arrowSelect = (topArr, arrow)=>{
    if(arrow === '1'){
        rightRotate(topArr)
    }else{
        leftRotate(topArr)
    }
}
const rotating2 = (topniArr, index, arrow)=>{
    if(index === 0){
        if(topniArr[index][2] !== topniArr[index+1][6]){
            let sw = true;
            const restArr = []
            for(let i = index+1 ; i<3; i++){
                if(topniArr[i][2] === topniArr[i+1][6]){
                    break;
                }
                if(sw){
                    restArr.push({index : i+1, arrow: arrow})
                    sw = !sw;
                }else{
                    restArr.push({index : i+1, arrow : arrow ==="1" ? "-1" : "1"})
                    sw = !sw;
                }
            }
            for(let i = 0 ; i< restArr.length; i++){
                arrowSelect(topniArr[restArr[i].index], restArr[i].arrow)    
            }
            arrowSelect(topniArr[index], arrow)
            arrowSelect(topniArr[index+1], arrow ==="1" ? "-1" : "1")
        }
        else{
            arrowSelect(topniArr[index], arrow)
        }
    }else if(index === 1 || index === 2){
        if(topniArr[index][2] !== topniArr[index+1][6] && topniArr[index][6]=== topniArr[index-1][2]){
            let sw = true;
            const restArr = [];
            for(let i = index+1 ; i<3; i++){
                if(topniArr[i][2] === topniArr[i+1][6]){
                    break;
                }
                if(sw){
                    restArr.push({index : i+1, arrow : arrow})
                    sw = !sw;
                }else{
                    restArr.push({index : i+1, arrow :arrow ==="1" ? "-1" : "1" })
                    sw = !sw;
                }
            }
            for(let i = 0 ; i< restArr.length; i++){
                arrowSelect(topniArr[restArr[i].index], restArr[i].arrow)    
            }
            arrowSelect(topniArr[index], arrow)
            arrowSelect(topniArr[index+1], arrow ==="1" ? "-1" : "1")
        }
        else if(topniArr[index][2] !== topniArr[index+1][6] && topniArr[index][6]!== topniArr[index-1][2]){
            let sw = true;
            const restArr = []
            for(let i = index+1 ; i<3; i++){
                if(topniArr[i][2] === topniArr[i+1][6]){
                    break;
                }
                if(sw){
                    restArr.push({index : i+1, arrow : arrow})
                    sw = !sw;
                }else{
                    restArr.push({index : index+1, arrow: arrow ==="1" ? "-1" : "1"})
                    sw = !sw;
                }
            }
            sw = true;
            for(let i = index-1 ; i>0; i--){
                if(topniArr[i][6] === topniArr[i-1][2]){
                    break;
                }
                if(sw){
                    restArr.push({index : i-1, arrow : arrow})
                    sw = !sw;
                    
                }else{
                    restArr.push({index: i-1, arrow :arrow ==="1" ? "-1" : "1" })
                    sw = !sw;
                }
            }
            for(let i = 0 ; i< restArr.length; i++){
                arrowSelect(topniArr[restArr[i].index], restArr[i].arrow)    
            }
            arrowSelect(topniArr[index], arrow)
            arrowSelect(topniArr[index+1], arrow ==="1" ? "-1" : "1")
            arrowSelect(topniArr[index-1], arrow ==="1" ? "-1" : "1")
        }else if(topniArr[index][2] === topniArr[index+1][6] && topniArr[index][6]!== topniArr[index-1][2]){
            let sw = true;
            const restArr = [];
            for(let i = index-1 ; i>0; i--){
                if(topniArr[i][6] === topniArr[i-1][2]){
                    break;
                }
                if(sw){
                    
                    restArr.push({index : i-1, arrow : arrow})
                    sw = !sw;
                }else{
                    restArr.push({index : i-1, arrow:arrow ==="1" ? "-1" : "1"})
                    sw = !sw;
                }
            }
            for(let i = 0 ; i< restArr.length; i++){
                arrowSelect(topniArr[restArr[i].index], restArr[i].arrow)    
            }
            arrowSelect(topniArr[index], arrow)
            arrowSelect(topniArr[index-1], arrow ==="1" ? "-1" : "1")     
        }else{
            arrowSelect(topniArr[index], arrow)
        }
               
    }else if(index === 3){
        if(topniArr[index][6] !== topniArr[index-1][2]){
            let sw = true;
            const restArr = [];
            for(let i = index-1 ; i>0; i--){
                if(topniArr[i][6] === topniArr[i-1][2]){
                    break;
                }
                if(sw){
                    
                    restArr.push({index : i-1, arrow : arrow})
                    sw = !sw;
                }else{
                    restArr.push({index : i-1, arrow:arrow ==="1" ? "-1" : "1"})
                    sw = !sw;
                }
            }
            for(let i = 0 ; i< restArr.length; i++){
                arrowSelect(topniArr[restArr[i].index], restArr[i].arrow)    
            }
            arrowSelect(topniArr[index], arrow)
            arrowSelect(topniArr[index-1], arrow ==="1" ? "-1" : "1") 
        }else{
            arrowSelect(topniArr[index], arrow)
        }
        
    }
    
}

const solution = (topniArr, rotateArr)=>{
    for(let i = 0 ; i<rotateArr.length; i++){
        const index = parseInt(rotateArr[i][0])
        rotating2(topniArr, index-1, rotateArr[i][1])
    }
    let answer = 0;
    let cnt = 1;
    for(let i = 0 ; i<topniArr.length; i++){
        if(topniArr[i][0] === '1'){
            answer+=cnt;
        }
        cnt*=2;
    }
    return answer;
}

function init(file){
    var fs = require('fs');
    var input
    if(file){
        input = fs.readFileSync(file).toString().split('\n');
    }else{
        input = fs.readFileSync('/dev/stdin').toString().split('\n');
    }
    
    const topniArr = []
    const rotateArr = []
    for(let i = 0 ; i< 4; i++){
        topniArr.push(input[i].split(''))
    }
    for(let i = 5 ; i<input.length; i++){
        const arr = input[i].split(' ');
        rotateArr.push(arr)
    }
    const answer = solution(topniArr, rotateArr)
    
    console.log(answer)
}


init('./test.txt');

