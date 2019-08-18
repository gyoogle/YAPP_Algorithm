function solution(arrangement) {
    let answer = 0
    let stack = []
    let tmpanswer = []
    for(let i = 0; i<arrangement.length ; ){
        if(arrangement[i] === '(' && arrangement[i+1] !== ')'){
            stack.push(0)
            i++
        }
        else if(arrangement[i] === '(' && arrangement[i+1] === ')'){
            answer+=stack.length
            i +=2
        }
        else{
            answer += 1
            stack.pop()
            i++
        }
    }
    return answer;
}