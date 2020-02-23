import java.util.*;
class Solution {
    public String[] solution(String[] record) {
        Map<String,String> hash= new HashMap<String,String>();
        String enter = "님이 들어왔습니다.";
        String leave = "님이 나갔습니다.";
        StringTokenizer str;
        String[] StrState = new String[100000];
        String[] StrId = new String[100000];
        int j=0;
        String state;
        for(int i =0;i<record.length;i++){
            str = new StringTokenizer(record[i]," ");
            state = str.nextToken();
            if(state.equals("Change")){
                String id = str.nextToken();
                String nick = str.nextToken();
                hash.put(id,nick);
            }
            if(state.equals("Enter")){
                String id = str.nextToken();
                String nick = str.nextToken();
                StrState[j]=enter;
                StrId[j]=id;
                hash.put(id,nick);
                j++;
            }
            if(state.equals("Leave")){
                String id = str.nextToken();
                StrState[j]=leave;
                StrId[j]=id;
                j++;
            }
            
        }
        String[] answer = new String[j];
        for(int i=0;i<j;i++){
            answer[i] = hash.get(StrId[i])+StrState[i];
        }
        return answer;
    }
}