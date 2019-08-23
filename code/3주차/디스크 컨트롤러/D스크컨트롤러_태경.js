
function solution(jobs) {
    var answer = 0;
    let acci= 0 ;
    let i = 0;
    let copy = jobs.map(e=>e)
    while(i< jobs.length){
        const canNow = copy.filter(v=> acci >= v[0]) //현재 돌릴수 있는 리스트들 가져와보기
        if(canNow.length === 0 ) { //만일 없을 경우 누적시간을 1증가시키고 다시 체크해본다
            acci++
            continue
        }
        const best = canNow.map(v => v).reduce((acc,i)=> acc[1]>i[1] ? i:acc) 
        //그중 가장 짧은 시간을 가진녀석뽑아내기 1차원 배열로 리턴됨
        const findingI = copy.findIndex(v=> v[1]===best[1] && v[0]===best[0])
        // best의 도착시간과 진행시간이 같은 요소를 원본을 복사한 copy배열에서 그 인덱스번호를 찾아낸다
        acci+=best[1] // 현재 총 진행시간을 더하고
        answer += acci - copy[findingI][0] // 반환시간을 누적시킨다
        copy.splice(findingI, 1) //findIndex로 찾아낸 배열번호를 copy에서 제거
        i++ //그리고 한개스케쥴링을 완료했다는 의미로 1만큼 올린다
    }
    
    return parseInt(answer/jobs.length);
}