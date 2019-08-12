function solution(participant, completion) {
    let key = new Map()
    completion.map((c)=>{
        if(key.has(c)){
            key.set(c, key.get(c)+1)
        }
        else{
            key.set(c, 1)
        }
    })
    for(let entry of participant){
        if(key.has(entry) && key.get(entry) !== 0){
            key.set(entry, key.get(entry)-1)
        }else{
            return entry
        }
    }
}