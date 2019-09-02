function solution(array, commands) {
    var answer = [];
    for(let i = 0; i< commands.length; i++){
        try{
            let copy = array.map(e => e).slice(commands[i][0]-1, commands[i][1]).sort((a,b)=> a-b)
        answer.push(copy[commands[i][2]-1])    
        }catch(e){
            continue;
        }
        
    }
    return answer;
}