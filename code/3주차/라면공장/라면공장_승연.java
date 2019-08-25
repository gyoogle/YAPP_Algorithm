import java.util.*;

class Solution {
    public int solution(int stock, int[] dates, int[] supplies, int k) {
        int answer = 0;
        int j=0;
        PriorityQueue<Integer> heap= new PriorityQueue<>(Collections.reverseOrder());
        
        for(int i=0;i<k;i++){
            if(j<dates.length && dates[j]==i){
                heap.add(supplies[j]);
                j++;
            }
            if(stock==0){
                stock += heap.poll();
                answer++;
            }
            stock--;
        }
        return answer;
    }
}