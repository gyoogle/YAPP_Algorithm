function findAnswer(numbers, k, target, index)
{
    if(index == numbers.length){
        if(k == target){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return findAnswer(numbers, k + numbers[index] , target, index + 1) + findAnswer(numbers, k - numbers[index] , target ,index + 1)
    }
}

function solution(numbers, target) {  
    
    return findAnswer(numbers, 0, target, 0);
}
