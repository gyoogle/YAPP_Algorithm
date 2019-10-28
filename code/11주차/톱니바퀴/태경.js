
const rightRotate = (arr)=>{
    arr.push(arr.shift())
}
const leftRotate = (arr)=>{
    arr.unshift(arr.pop())
}
const selectRotate = (current, arrow, another = [0,0,0,0,0,0,0,0], another2 = [0,0,0,0,0,0,0,0,0])=>{
    if(arrow === '1'){
        rightRotate(current)
        leftRotate(another)
        leftRotate(another2)
    }else{
        leftRotate(current)
        rightRotate(another)
        rightRotate(another2)
    }
}
const rotating = (topniArr, index, arrow) =>{
    if(index === 0 ){
        if(topniArr[index][2] !== topniArr[index+1][6]){
            selectRotate(topniArr[0], arrow, topniArr[1])
        }else{
            selectRotate(topniArr[0], arrow)
        }
    }else if(index === 3){
        if(topniArr[index][6] !== topniArr[index-1][2]){
            selectRotate(topniArr[index], arrow, topniArr[index-1])
        }else{
            selectRotate(topniArr[index], arrow)
        }
    }else{
        if(topniArr[index][6] !== topniArr[index-1][2] && topniArr[index][2] !== topniArr[index+1][6]){
            selectRotate(topniArr[index], arrow, topniArr[index-1], topniArr[index+1])
        }else if (topniArr[index][6] !== topniArr[index-1][2] && topniArr[index][2] === topniArr[index+1][6] ){
            selectRotate(topniArr[index], arrow, topniArr[index-1])
        }else if (topniArr[index][6] === topniArr[index-1][2] && topniArr[index][2] !== topniArr[index+1][6]){
            selectRotate(topniArr[index], arrow, topniArr[index+1])
        }
        else{
            selectRotate(topniArr[index], arrow)
        }
    }
}
const solution = (topniArr, rotateArr)=>{
    
    for(let i = 0 ; i<rotateArr.length; i++){

        const index = parseInt(rotateArr[i][0])
        rotating(topniArr, index, rotateArr[i][1])
        
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

