import java.util.*;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        int[] tmp={};
        
        for(int i=0;i<commands.length;i++){
            tmp=Arrays.copyOfRange(array,commands[i][0]-1,commands[i][1]);
            Arrays.sort(tmp);
            answer[i] =tmp[commands[i][2]-1];
        }
        return answer;
    }
}