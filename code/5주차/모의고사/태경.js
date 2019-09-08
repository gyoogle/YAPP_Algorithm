function solution(answers) {
    var answer = [];
    let fcnt = 0;
    let scnt = 0;
    let tcnt = 0;
    const fselect = [1,2,3,4,5];
    const sselect = [1,3,4,5];
    const tselect = [3,1,2,4,5];
    let sindex = 0;
    let tindex = 0; 
    for(let i = 0; i<answers.length; i++){
        if(answers[i] === fselect[i%5]) fcnt++;
        if(i%2 === 0 && answers[i] === 2 || i%2 ===1 && answers[i] === sselect[sindex] ){
            scnt++;
        }
        
         
        if(answers[i] === tselect[tindex]){
            tcnt++
        }
        if(i%2 === 1){
            sindex = (sindex+1)%4
            tindex = (tindex+1)%5
        } 
    }
    const fsmax = fcnt > scnt ? fcnt : scnt;
    const totmax = fsmax > tcnt ? fsmax : tcnt;
    if(totmax === fcnt) answer.push(1)
    if(totmax === scnt) answer.push(2)
    if(totmax === tcnt) answer.push(3)
    answer.sort((a,b)=> a-b)
    return answer;
}