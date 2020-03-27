'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the isBalanced function below.
function isBalanced(s) {
    const stack = [];
    let stackTop = -1;
    const sArray = s.split('');
    const pushMap = {
        '(' : 0,
        '{' : 1,
        '[' : 2
    }
    const popMap = {
        ')' : 0,
        '}' : 1,
        ']' : 2
    }
    for(let i = 0 ; i < sArray.length ; i++){
        try{
            if(popMap[sArray[i]] !== undefined) {
                const topEl = stack.pop();
                if(popMap[sArray[i]] !== pushMap[topEl]) {
                    return 'NO'
                }
            } else {
                stack.push(sArray[i]);
            }
        }catch{
            stack.push(sArray[i]);
            continue;
        }
    }
    if(stack.length === 0){
        return 'YES';
    }else{
        return 'NO';
    }
    

}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const t = parseInt(readLine(), 10);

    for (let tItr = 0; tItr < t; tItr++) {
        const s = readLine();

        let result = isBalanced(s);

        ws.write(result + "\n");
    }

    ws.end();
}
