import java.util.*;
class Solution {
    public int[] solution(int[] heights) {
        Stack<Integer> stack = new Stack <Integer>();
        int len = heights.length;
        int[] answer = new int[len];
        Arrays.fill(answer,0);
        int k = 0;
        for(int i=0;i<len;i++){
            stack.push(heights[i]);
        }
        for(int i=answer.length-1;i>=0;i--){
            k=stack.pop();
            for(int j= i;j>=0;j--){
                if(k<heights[j]){
                    answer[i]=j+1;
                    break;
                }
            }
        }
        return answer;
    }
}