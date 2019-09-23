import java.util.*;
class Solution {
    public long solution(int N) {
        long answer = 0;
        long[] number = new long[N+1];
        number[1]=1;
        for(int i = 2;i<number.length;i++){
            number[i]=number[i-1]+number[i-2];
        }
        answer=number[N]*4+number[N-1]*2;
        return answer;
    }
}