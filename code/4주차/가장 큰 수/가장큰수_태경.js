function solution(numbers) {
    var answer = '';
    let copy = numbers.map(e=> e+'')
    copy.sort((a,b)=>{
        while(true){
            if(a.length === b.length)return b-a
            else if(a.length > b.length){
                b += b[b.length-1]
            }else{
                a += a[a.length-1]
            }
        }
    })
    copy.map((e)=> {
        if(e >= 0) answer+=e
    })
    return answer;
}


function solution(numbers) {
    var answer = '';
    answer = numbers.sort((a,b)=>{
        return (''+b+a) - (''+a+b)
    }).join('')
    return answer[0] ==='0'? '0' : answer;
}