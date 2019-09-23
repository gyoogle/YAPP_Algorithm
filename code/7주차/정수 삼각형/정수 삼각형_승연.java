import java.util.*;
class Solution {
    public int solution(int[][] triangle) {
        int answer = 0;
        int[][] arr= new int[triangle.length][triangle.length];
        arr[0][0]=triangle[0][0];
        //초기화
        for(int i= 1;i<triangle.length;i++){
            arr[i][0]=arr[i-1][0] +triangle[i][0];
            arr[i][i]=arr[i-1][i-1]+triangle[i][i];
       }
        for(int i=2;i<triangle.length;i++){
            for(int j=1;j<i;j++){
                arr[i][j]=Math.max(arr[i-1][j-1],arr[i-1][j])+triangle[i][j];
            }
        }
        for(int i=0;i<arr.length;i++){
            answer=Math.max(answer,arr[arr.length-1][i]);
        }
        return answer;
    }
}