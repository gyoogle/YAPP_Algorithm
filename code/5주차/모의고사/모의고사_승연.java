import java.util.*;
class Solution {
    public int[] solution(int[] answers) {
        int[] pattern1 = {1,2,3,4,5};
        int[] pattern2 = {2,1,2,3,2,4,2,5};
        int[] pattern3 = {3,3,1,1,2,2,4,4,5,5};
        int[] score= new int[3];
        for(int i=0;i<answers.length;i++){
            if(pattern1[i%5]==answers[i]){
                score[0]++;
            }   
            if(pattern2[i%8]==answers[i]){
                score[1]++;
            }
            if(pattern3[i%10]==answers[i]){
                score[2]++;
            }
        }
        int Max=Math.max(score[0],Math.max(score[1],score[2]));
        ArrayList<Integer> temp= new ArrayList<>();
        for(int i=0;i<score.length;i++){
            if(score[i]==Max){
                temp.add(i+1);
            }
        }
        int[] answer= new int[temp.size()];
        for(int i =0;i<temp.size();i++){
            answer[i]=temp.get(i).intValue();
        }
        
        return answer;
    }
}