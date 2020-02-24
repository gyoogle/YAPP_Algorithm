import java.util.*;
class Solution {
    public int solution(String[][] clothes) {
        HashMap<String,Integer> hash = new HashMap<String,Integer>();
        int answer = 1;
        for(int i=0;i<clothes.length;i++){
            if(hash.containsKey(clothes[i][1])){
                hash.put(clothes[i][1],hash.get(clothes[i][1])+1);
            }else{
                hash.put(clothes[i][1],2);
            }
        }
        for(String keys:hash.keySet()){
            answer *= hash.get(keys); 
        }
        answer = answer-1;
        return answer;
    }
}