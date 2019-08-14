package Programmers;

public class ¼è¸·´ë±â {
	
	static char[] c;
	static int cnt;
	public int solution(String arrangement) {
        int answer = 0;
        
        c = arrangement.toCharArray();
        cnt = 0;
        
        for (int i = 0; i < c.length; i++) {
        	
        	if(c[i] == '(') {
        		cnt++;
        	}
        	else { // ')'
        		
        		if(c[i-1] == ')') {
        			answer += 1;
        			cnt--;
        		}
        		else
        			answer += (--cnt);
        	}
		}
        
        return answer;
    }
}
