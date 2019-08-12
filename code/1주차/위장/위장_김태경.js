function solution(clothes) {
    const key = new Map()
    clothes.map((c)=>{
        if(key.has(c[1])){
            key.set(c[1], key.get(c[1])+1)
        }else{
            key.set(c[1],1)
        }
        
    })
    let answer =1
    for(let i of key.values()){
        answer*=(i+1)
    }
    return answer -1
}