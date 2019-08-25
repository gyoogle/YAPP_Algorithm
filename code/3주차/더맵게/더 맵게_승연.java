import java.util.*;
class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
       PriorityQueue<Integer> heap = new PriorityQueue<>();
        for(int i: scoville){
            heap.add(i);
        }
       while(true){
            if(heap.peek()>=K) break;
            if(heap.size()==1) return -1;
            int temp= heap.poll()+(heap.poll()*2);
            heap.add(temp);
            answer++;
        }
        return answer;
    }
}