function checkCost(A,B){
    
    if(A.length != B.length)
    {
        return -1;
    }
    else{
        var Aobj = new Array(26).fill(0);
        var Bobj = new Array(26).fill(0);
        for(var i = 0 ; i < A.length ; i ++){
            var Aascii = A.charCodeAt(i);
            var Bascii = B.charCodeAt(i);

            Aobj[Aascii - 97] += 1;
            Bobj[Bascii - 97] += 1;
        }

        if(JSON.stringify(Aobj) == JSON.stringify(Bobj))
        {
            var result = 0;
            for(var i = 0 ; i < A.length ; i ++){
                if(A[i] != B[i]){
                    result ++;
                }                
            }
            return result;
        }
        else{
            return -1;
        }
    }
}

function solution(file){
    var fs = require('fs');
    var input_line;
    if(file == undefined){
        input_line = fs.readFileSync('/dev/stdin').toString().split(/\s+/g);
    }
    else{
        input_line = fs.readFileSync(file).toString().split(/\s+/g);
    }

    var sentence = input_line[0];
    var words = input_line.splice(2);

    var dp = new Array(sentence.length+1);
    dp[0] = 0;

    for(var i = 1 ; i < dp.length ; i ++){

        var levelCost = 10000;

        for(var j = 0 ; j < i ; j ++){
            var prevCost = dp[j];
            var target = sentence.substring(j,i);

            var curCost = 10000;

            for(var w = 0 ; w < words.length ; w ++){
                var cost = checkCost(target, words[w],(i));

                if(cost >= 0 && cost < curCost){
                    curCost  = cost;
                }
                /*
                if(i == 5){
                    console.log(j, prevCost,curCost, target,words[w], levelCost)
                }
                */
            }
            if(curCost != 10000 && prevCost != -1){
                if(prevCost + curCost < levelCost){
                    levelCost = (prevCost != -1 ? prevCost : 0) + curCost;
                }
            }
        }

        if(levelCost == 10000){
            dp[i] = -1;
        }
        else{
            dp[i] = levelCost;
        }

        //console.log(i , dp[i]);
    }

    return dp[sentence.length];
    
}

console.log(solution('./ex1.txt'));


//console.log(checkCost('one','neo'));
