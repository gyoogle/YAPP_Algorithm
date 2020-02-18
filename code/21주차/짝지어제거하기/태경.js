function solution(s)
{
    var answer = 0;
    // 문자열-> 배열로만든다
    const questions = s.split('')
    //스택 선언
    const stack = []; 
    let stackLength = -1; //스택의 가장 마지막 번호를 표시
    //왼쪽부터 하나씩 넣는다
    for(let i = 0 ; i < questions.length; i++){
        //스택이 비어있을경우 exception 발생된다
        try{
            if(stack[stackLength] === questions[i]){
                //가장 마지막 번호와 현재 검사할 번호가 같으면 뺀다
                stack.pop()
                stackLength--;
            }else{
                //가장 마지막 번호와 현재 검사할 번호가 다르면 넣는다
                stack.push(questions[i])
                stackLength++
            }
        }catch(err){
            //비어있을경우 그냥 집어넣고 length를 1만큼 올린다
            stack.push(questions[i]);
            stackLength++
            continue;
        }
    }
    //스택이 비어있는지 확인
    if(stack.length === 0){
        answer = 1;
    }
    return answer;
}