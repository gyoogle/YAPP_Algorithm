function solution(file){
    var fs = require('fs');
    var input_line;
    if(file == undefined){
        input_line = fs.readFileSync('/dev/stdin').toString().split('\n');
    }
    else{
        input_line = fs.readFileSync(file).toString().split('\n');
    }

    var N = parseInt(input_line[0]);

    if(N <= 9)
        return N;

    var countArray = new Array(10).fill(1);
    var counts = [countArray];
    var sum = 9;
    var curLevel = 0;

    /*
        예시 : 78
        
        counts[k][j] 는 
        j * 10 ^ k 부터 
        ((j + 1) * 10 ^ k) - 1 까지 
        몇 개의 낮은 자리수가 있는지 보여준다. 
        (예시 : 600 ~ 699)
        counts : 
        [
            [ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ],          => 1의 자리수
            [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ],          => 10의 자리수
            [ 0, 0, 1, 3, 6, 10, 15, <3 empty items> ] => 100의 자리수
        ] 89

        STEP 1-a: 자신보다 바로 아래 자리수의 배열 중, 
            자신보다 작은 숫자에 해당하는 값을 모두 가져와 더한 값을 자신의 위치에 배치하고, 
            SUM 값에 더한다.
            SUM 값이 N보다 커지면 STEP1을 중단한다.

        STEP 1: 자리수를 한 자리씩 올리면서 STEP 1-a를 반복한다. 
            SUM 값이 N보다 커지거나 10^10의 자리수까지 탐색하면 STEP2를 중단한다.
            


        STEP 1이 끝나면  6XX 형태의 결과값은 찾을 수 있지만, 아래자리수의 숫자를 알 수 없기때문에 역산한다(STEP2)        
    */

    //STEP1

    while(N > sum && curLevel < 10)
    {
        curLevel ++;
        var countArray = new Array(10);
        countArray[0] = 0;
        counts.push(countArray);
        var levelSum = 0;

        for(var i = 1 ; i <= 9 ; i ++){
            levelSum += counts[curLevel - 1 ][i -1] ;
            sum += levelSum ;
            countArray[i] =  levelSum;

            if(N <= sum)
                break;
        }        
    }

    //console.log(counts,sum);

    /*
        예시) 
        ptr = 6

        1 5 84 78 
        1 4 80 78

        10의 자리수에서 ptr보다 작은 숫자의 위치를 비교해가면서 10의자리숫자를 추적한다.
        10의 자리 숫자를 찾으면 ptr을 10의 자리 숫자로 초기화한다.

        0 2 79 78
        0 1 78 78

        1의 자리수에서 ptr보다 작은 숫자의 위치를 비교해가면서 1의자리숫자를 추적한다.
        1의 자리 숫자를 찾으면 ptr을 1의 자리 숫자로 초기화한다.
    */

    
    //STEP2

    if(N > sum)
        return -1;
    else{
        var ptr = i;
    }

    var answer = '' + ptr;
    curLevel --;


    while(curLevel >= 0){

        var levelAnswer = ptr -1;

        for(var i = ptr-1 ; i >= 0 ;  i --){

            levelAnswer = i;

            if(sum - counts[curLevel][i] >= N){
                
                sum -= counts[curLevel][i];
                //console.log(curLevel,i,sum,N);
            }
            else{
                break;
            }
        }
        curLevel --;
        answer += levelAnswer;

        ptr = levelAnswer;
    }

    return answer;
}

console.log(solution('./ex1.txt'));
