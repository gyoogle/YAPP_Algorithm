function solution(n, lost, reserve) {
    var answer = 0;
    answer = n-lost.length;
    lost.sort((a,b)=> a-b)
    reserve.sort((a,b)=> a-b)
    lost = lost.filter((e)=>{
        const index=reserve.findIndex(v=> e === v)
        if(index !== -1){
            answer++
            reserve[index] = -1
        }
        return index === -1
    })
    lost.map((e)=>{
        const index=reserve.findIndex(v=> e +1 === v || e-1 === v)
        if(index !== -1){
            answer++
            reserve[index] = -1
        }
    })
    return answer;
}