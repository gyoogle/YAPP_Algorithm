"use strict";

const fs = require("fs");

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", inputStdin => {
    inputString += inputStdin;
});

process.stdin.on("end", _ => {
    inputString = inputString
        .replace(/\s*$/, "")
        .split("\n")
        .map(str => str.replace(/\s*$/, ""));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the pairs function below.
function pairs(k, arr) {
    const hashMap = {}; // 검색할 키밸류 객체 생성
    let cnt = 0; // 리턴할 카운트

    /**
     * 맵 테이블 셋팅
     */
    for (let i = 0; i < arr.length; i++) {
        if (hashMap[arr[i]] !== 1) {
            hashMap[arr[i]] = 1;
        }
    }

    /**
     *  검색해서 카운트 올리기
     */
    for (let i = 0; i < arr.length; i++) {
        const target1 = arr[i] + k;
        if (hashMap[target1] === 1) {
            cnt++;
        }
    }
    return cnt; //리턴
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const nk = readLine().split(" ");

    const n = parseInt(nk[0], 10);

    const k = parseInt(nk[1], 10);

    const arr = readLine()
        .split(" ")
        .map(arrTemp => parseInt(arrTemp, 10));

    let result = pairs(k, arr);

    ws.write(result + "\n");

    ws.end();
}
