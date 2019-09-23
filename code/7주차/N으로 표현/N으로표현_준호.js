function solution(N, number) {
    
    var caseObj = {};
    
    var firstKey = '' ;
    firstKey += N;
    caseObj[firstKey] = 1  ;
    
    for(let t = 2 ; t <= 4 ; t ++){
        
        var keys = Object.keys(caseObj);
        
        for(let i = 0 ; i < keys.length ; i ++){
            for(let j = 0 ; j < keys.length; j ++){
                let first = keys[i] / 1;
                let second = keys[j] / 1;
                
                if(first < second){
                    let tmp = second;
                    second = first;
                    first = tmp;
                }
                
                let target ;
                
                target = first + second;
                if(!caseObj.hasOwnProperty(target + '')||
                  caseObj[target + '']  > caseObj[first + ''] + caseObj[second + '']){
                    caseObj[target + '']  = caseObj[first + ''] + caseObj[second + ''];
                }
                
                target = parseInt(first / second);
                if(!caseObj.hasOwnProperty(target + '') ||
                  caseObj[target + '']  > caseObj[first + ''] + caseObj[second + '']){
                    caseObj[target + '']  = caseObj[first + ''] + caseObj[second + ''];
                }
                
                target = first * second;
                if(!caseObj.hasOwnProperty(target + '')  ||
                  caseObj[target + '']  > caseObj[first + ''] + caseObj[second + '']){
                    caseObj[target + '']  = caseObj[first + ''] + caseObj[second + ''];
                }
                
                target = first - second;
                if(!caseObj.hasOwnProperty(target + '') ||
                  caseObj[target + '']  > caseObj[first + ''] + caseObj[second + '']){
                    caseObj[target + '']  = caseObj[first + ''] + caseObj[second + ''];
                }
            }
        }
        
        firstKey += N;
        caseObj[firstKey] = t  ;
    }
    
    
    if(caseObj.hasOwnProperty(number + '')){
        return caseObj[number + ''];
    }
    else{

        return -1;
    }

}