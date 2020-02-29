import java.util.*;
class Solution {
    public String solution(String number, int k) {
        String answer = "";
        char[] result = new char[number.length()-k];
        Stack<Character> stack = new Stack<Character>();
        for(int i=0;i<number.length();i++){
            char ch = number.charAt(i);
            while(!stack.isEmpty()&&k>0){
                if(stack.peek()<ch){
                    k--;
                    stack.pop();
                }
                else break;
            }
            stack.push(ch);
        }
        for(int i=0;i<result.length;i++){
            result[i]=stack.get(i);
            answer+=result[i];
        }
        
        return answer;
    }
}