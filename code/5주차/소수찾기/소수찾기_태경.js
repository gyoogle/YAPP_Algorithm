function solution(numbers) {
    const arr = numbers.split('')
    let copyarr = arr.map(e=>e)
    const answerarr =[];
    for(let i = 0; i<arr.length; i++){
        treeSearch(arr[i], copyarr.filter((e,index)=> index!=i) , arr, answerarr) 
    }
    const answer = []
    for(let i = 0 ; i<answerarr.length ; i++){
        if(answer.indexOf(answerarr[i]) === -1){
            answer.push(answerarr[i])
        }
    }
    
    return answer.length;
}
function treeSearch(root, arr, countarr,answerarr){
    
    chk(parseInt(root), answerarr)
    if(countarr.length === root.length){
        return;
    }
    for(let i = 0 ; i<arr.length; i++){
        treeSearch(root+arr[i], arr.filter((e,index)=> index!=i), countarr, answerarr)
    }
}
function chk(number, answerarr){
    if(number < 2) return false;
    for(let i = 2 ; i<number/2+1 ; i++){
        if (number%i === 0) return false
    }
    answerarr.push(number)
}