import java.util.*;
class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 1;
        PriorityQueue<Integer> priorityqueue = new PriorityQueue<Integer>(Collections.reverseOrder());
        for(int j:priorities){
            priorityqueue.add(j);
        }
        while(!priorityqueue.isEmpty()){
            for(int i =0;i<priorities.length;i++){
                if(priorities[i]==priorityqueue.peek()){
                    if(i==location) return answer;
                    else {
                        answer++;
                        priorityqueue.poll();
                    }
                }
            }
        }
        return answer;
    }
}