function solution(record) {
    var answer = [];
    //message key: value값
    const messageEnter = {
        "Enter": "들어왔습니다.",
        "Leave": "나갔습니다."
    }

    //user 변경을 감지해서 바꿀 수 있는 key: value값
    const userList = {};
    //일단 아이디랑, 메세지를 쌓아둘 수 있는 메세지 리스트 
    const messageList = [];

    //레코드에 있는 것 들을 하나 씩 뺀다.
    for(let i = 0 ; i < record.length; i++){
        const oneLine = record[i].split(' ');//한 메세지를 뽑아낸다
        const action = oneLine[0]; //처음에는 액션이 들어온다
        const userNumber = oneLine[1]; // 두번째에는 고유아이디
        const targetName = oneLine[2]; // 세번째는 유저 닉네임이 들어온다
        //유저 고유번호가 10보다 크거나 0일 경우 리스트에 추가도 하지않는다
        if(userNumber.length > 10 || userNumber.length=== 0){
            continue;
        }
        //유저 아이디가 있는데 10보다 크거나 0일 경우에도 리스트에 추가하지않는다.
        if(targetName != null){
            if(targetName.length === 0 || targetName.length > 10)
                continue;
        }
        //유저 아이디가 있다는 것은 변경을 했다는 것이기에, 그 변경 값을 userList에 갱신시킨다.
        if(targetName != null){
            userList[userNumber] = targetName
        }
        //action이 Change일 경우 리스트에 쌓지 않는다.
        if(action != "Change"){
            messageList.push([userNumber, action]);
        }
    }
    
    //만세만세 템플릿문자열
    for(let i = 0 ; i < messageList.length; i++){
        //userList에 있는 keyValue값으로 유저이름을
        //messageEnter에 있는 keyValue 값으로 액션을 넣는다.
        answer.push(`${userList[messageList[i][0]]}님이 ${messageEnter[messageList[i][1]]}`)
    }
    
    return answer;
}