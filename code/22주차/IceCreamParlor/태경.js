"use strict";

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", inputStdin => {
    inputString += inputStdin;
});

process.stdin.on("end", function() {
    inputString = inputString
        .replace(/\s*$/, "")
        .split("\n")
        .map(str => str.replace(/\s*$/, ""));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the whatFlavors function below.
function whatFlavors(cost, money) {
    const hashMap = {}; //검색할 hash테이블
    const answer = []; //answerStr로 바꿔줄 배열

    /**
     * 테이블 초기화 작업
     */
    for (let i = 0; i < cost.length; i++) {
        if (!hashMap[cost[i]]) {
            hashMap[cost[i]] = [i + 1];
        } else {
            hashMap[cost[i]] = [...hashMap[cost[i]], i + 1];
        }
    }

    for (let i = 0; i < cost.length; i++) {
        const target = money - cost[i]; //타겟은 내가 든 돈과 해당 아이스크림을 빼고 살수있는 금액
        if (target <= 0) { //타겟이 0 이하면 두 개 섞기 불가능
            continue;
        }
        if (!hashMap[target]) { // 타겟이 테이블에 없으면 살수가 없음
            continue;
        }
        const check = hashMap[target].findIndex(el => el > i + 1); // 타겟에 현재 인덱스보다 큰게 있는지 확인
        if (check == -1) { // 없을 경우 필요없음
            continue;
        }
        answer.push(i + 1); // 있으면 작은 것 부터 넣고
        answer.push(hashMap[target][check]); // 큰것을 넣어서
    }
    const answerStr = answer.map(el => el + "").join(" "); // 주어진 문자열로 변환
    console.log(answerStr);
}

function main() {
    const t = parseInt(readLine(), 10);

    for (let tItr = 0; tItr < t; tItr++) {
        const money = parseInt(readLine(), 10);

        const n = parseInt(readLine(), 10);

        const cost = readLine()
            .split(" ")
            .map(costTemp => parseInt(costTemp, 10));

        whatFlavors(cost, money);
    }
}
