

const readline = require('readline');

const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

const solution=(number)=>{
    
    let i = 64;
    let cnt = 0 ;
    while(i > 0){
        if(number === i){
            cnt++;
            break;
        }
        if(number > i){
            
            number = number-i
            cnt++
        }
        i= parseInt(i/2);
        
    }
    return cnt;
    
}
rl.on('line', function(answer) {
    
    answer = parseInt(answer)
    let cnt = solution(answer)
    console.log(cnt)
	rl.close();
});

