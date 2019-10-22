

const readline = require('readline');

const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

const solution=(number)=>{
    
}
function init(){
    const inputArr = []
    const rotateArr = []
    const topniArr =[]
    rl.on('line', function(line) {                     
        if(line=== ""){
            console.log(inputArr)
            for(let i = 0 ; i<4; i++){
                topniArr.push(inputArr[i])
            }
            for(let i = 5; i<inputArr.length; i++){
                rotateArr.push(inputArr[i])
            }
            console.log("topni", topniArr)
            console.log("rotateArr", rotateArr)
            rl.close();
        }
        inputArr.push(line)    
    });    
    

}


init();

