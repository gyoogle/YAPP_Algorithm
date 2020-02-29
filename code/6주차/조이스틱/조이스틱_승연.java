import java.util.*;
class Solution {
    public int solution(String name) {
        char[] ch= name.toCharArray();
        int answer =0;
        int acount =0;
        for(int i=1;i<ch.length;i++){
            if(ch[i]!='A'){
                break;
            }
            acount++;
        }
        for(int i=0;i<ch.length;i++){
            int tmp =ch[i]-'A';
            if(tmp>=13){
                tmp = 26-tmp;
            }
            answer+=tmp;
        }
        answer += ch.length-1-acount;
        return answer;
    }
}