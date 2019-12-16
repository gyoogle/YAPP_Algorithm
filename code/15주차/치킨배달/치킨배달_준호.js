function solution(file){
    var fs = require('fs');
    var input_line;
    if(file == undefined){
        input_line = fs.readFileSync('/dev/stdin').toString().split('\n');
    }
    else{
        input_line = fs.readFileSync(file).toString().split('\n');
    }

    var [N, M]  = input_line[0].split(/\s+/g).map(i => parseInt(i));

    var houses = [] , chickens = [], dis = [];

    for(var i = 0 ; i < N ; i ++){
        var vec = input_line[i + 1].split(/\s+/g).map(i => parseInt(i));

        for(var j = 0 ; j < N ; j ++){
            if(vec[j] == 1){
                houses.push([i,j]);
            }
            else if(vec[j] == 2){
                chickens.push([i,j]);
            }
        }
    }

    var chickLen = chickens.length;
    var houseLen = houses.length

    for(var c = 0 ; c < chickLen ; c ++){

        dis.push([]);

        for(var h = 0 ; h < houseLen ; h ++){
            dis[c].push(Math.abs(houses[h][0] - chickens[c][0]) + Math.abs(houses[h][1] - chickens[c][1]));
        }
    }
    //console.log("new" ,dis);


    var minDis = 100000000;

    function combination(combArr, n, r , index , target, arr){
        if(r == 0){
            //console.log("Test " , combArr);
            var combDis = [];
            for(var i = 0 ; i < combArr.length ; i ++){
                combDis.push(arr[combArr[i]].slice(0));
            }
            //console.log("combDis " , combDis);
            var dis = [];

            for(var i = houseLen - 1 ; i >= 0 ; i --){
                dis.push([]);
                for(c = 0 ; c < combDis.length ; c ++){
                    dis[dis.length - 1].push(combDis[c].pop());
                }
            }
            //console.log("dis" , dis);

            var sum = 0;

            for(var i = 0 ; i < houseLen ; i ++){
                sum += dis[i].sort((a,b) => a-b)[0]
            }

            if(minDis > sum){
                minDis = sum;
            }
            return ;
        }
        else if(target == n)
            return;
        else{
            combArr[index] = target;
            combination(combArr, n , r - 1, index + 1, target + 1,arr);
            combination(combArr, n , r , index, target + 1,arr);
        }
    }


    combination([], chickLen, M, 0, 0, dis);

    return minDis;
}

for(var i = 0 ; i < 4 ; i ++){
    console.log(solution('./ex'+i + '.txt'));
}

