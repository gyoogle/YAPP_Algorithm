const solution = (N, K)=>{
    const array = new Array(K)
    for(let i = 0 ; i<array.length; i++){
        array[i] = new Array(N)
    }
    for(let i = 0 ; i<array.length; i++){
        array[i][0] = i+1;
    }
    for(let i = 0 ; i<array[0].length ; i++){
        array[0][i] = 1;
    }
    for(let i = 1; i<K; i++){
        for(let j = 1; j<N; j++){
            array[i][j] = (array[i-1][j] + array[i][j-1]) % 1000000000;
        }
    }
    console.log(array[K-1][N-1])
}
const init = (file)=>{
    var fs = require('fs');
    var input
    if(file){
        input = fs.readFileSync(file).toString().split('\n');
    }else{
        input = fs.readFileSync('/dev/stdin').toString().split('\n');
    }
    const test = input[0].split(' ').map((el)=> parseInt(el))
    const n = test[0]
    const k = test[1]
    solution(n,k)
}

init('./input.txt')