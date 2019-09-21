function solution(number, k) {
    var answer = ''
    let arr = number.split('').map(e => parseInt(e))
    
    for(let i = 0 ; i < k ; i++){
        let j
        for( j= 0; j<arr.length-1; j++ ){
            if(arr[j] < arr[j+1]){
                break;
            }
        }
        arr.splice(j,1)
    }
    for(let i = 0 ; i< arr.length; i++){
        answer+=arr[i]
    }
    return answer;
}


function solution(number, k) {
    const answer = []
    let head = 0
    let del = k

    answer.push(number[head++])
    while(answer.length < number.length - k || head < number.length) {
        if(del && answer[answer.length-1] < number[head]) {
            answer.pop()
            del--
            continue
        }
        answer.push(number[head++])
    }

    return answer.slice(0, number.length - k).join('')
}
