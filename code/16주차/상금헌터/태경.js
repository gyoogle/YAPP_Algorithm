const returnMoney = (rank, round)=>{
    if(rank === 0 ) return 0
    if(round === 1){
        if(rank === 1)  return 5000000
        else if(rank <= 3) return 3000000
        else if(rank <= 6) return 2000000
        else if(rank <= 10) return 500000
        else if(rank<= 15) return 300000
        else if(rank<= 21) return 100000
        return 0
    }else{
        if(rank === 1) return 5120000
        else if(rank <= 3) return 2560000
        else if(rank <= 7) return 1280000
        else if(rank <= 15) return 640000
        else if(rank <= 31) return 320000
        return 0
    }
}
const solution = (data)=>{
    for(let i = 0 ; i<data.length; i++){
        let tot = returnMoney(data[i][0], 1)+ returnMoney(data[i][1], 2) ;

        console.log(tot)
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
    const data = input.map((el)=>{
        return el.split(' ').map((num)=> parseInt(num))
    })
    solution(data)
}


init('./test.txt');