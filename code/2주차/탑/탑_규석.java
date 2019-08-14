package Programmers;

public class ž {

	public int[] solution(int[] heights) {
        int[] answer = new int[heights.length];
        
        answer[0] = 0;        
        
        for (int i = 1; i < answer.length; i++) {
			
        	for (int j = i; j >= 0; j--) {
				if(heights[i] < heights[j]) {
					answer[i] = j+1;
					break;
				}
			}
        	
		}
        return answer;
    }

}
