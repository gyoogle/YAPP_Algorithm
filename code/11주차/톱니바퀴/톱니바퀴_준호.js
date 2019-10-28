class wheel {


    constructor(data){
        this.data = JSON.parse(JSON.stringify(data));
    }

    get left(){
        return this.data[6];
    }
    get right(){
        return this.data[2];
    }

    get top(){
        return this.data[0];
    }

    get v(){
        return this.data;
    }

    turn(direction){
        if(direction == 1){
            this.data.unshift(this.data.pop());
        }
        else{
            this.data.push(this.data.shift());
        }
    }
}

function solution(file){
    var fs = require('fs');
    var input_line;
    if(file == undefined){
        input_line = fs.readFileSync('/dev/stdin').toString().split('\n');
    }
    else{
        input_line = fs.readFileSync(file).toString().split('\n');
    }

    var wheels = [];

    for(var i = 0 ; i < 4 ; i ++){
        var data = input_line.shift().split('\r')[0].split('').map(x => parseInt(x));
        wheels.push(new wheel(data));
    }

    var times = parseInt(input_line.shift());


    for(var t = 0 ; t < times ; t ++){
        //console.log('---' + t)
        let workQueue = [];
        let searchingQueue = [];
        let visited = Array(4).fill(0);

        var work = input_line.shift().split(' ').map(x => parseInt(x));
        work[0] --;
        workQueue.push(work);
        searchingQueue.push(work);

        //BFS searching
        while(searchingQueue.length > 0){
            let current = (searchingQueue.shift());
            let curWheelNum = current[0];
            let curDir = current[1];

            visited[curWheelNum] = 1;

            var nextNum = curWheelNum + 1;

            if(nextNum < wheels.length && visited[nextNum] == 0){
                if(wheels[curWheelNum].right != wheels[nextNum].left){
                    workQueue.push([nextNum, curDir * -1]);
                    searchingQueue.push([nextNum, curDir * -1]);
                }
            }

            visited[nextNum] = 1;

            var nextNum = curWheelNum - 1;

            if(nextNum >= 0 && visited[nextNum] == 0){
                if(wheels[curWheelNum].left != wheels[nextNum].right){
                    workQueue.push([nextNum, curDir * -1]);
                    searchingQueue.push([nextNum, curDir * -1]);
                }
            }

            visited[nextNum] = 1;
        }

        //turn wheels
        while(workQueue.length > 0){
            let current = workQueue.shift();
            let curWheelNum = current[0];
            let curDir = current[1];

            wheels[curWheelNum].turn(curDir);


        }


       
    }

    var answer = 0;
    var k = 1;

    for(var i = 0 ; i < 4 ; i ++){
        answer += (wheels[i].top * k);
        k *= 2;
    }

    console.log(answer);
}

solution();
