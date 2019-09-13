import java.util.*;

class 체육복 {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = n - lost.length;
        
        Arrays.sort(lost);
        Arrays.sort(reserve);
        
        loop : for(int i = 0; i < lost.length; i++) {
            
            int student = lost[i];
            
            for(int j = 0; j < reserve.length; j++) {
                
                if(reserve[j] == student) {
                    answer++;
                    lost[i] = -1;
                    reserve[j] = -1;
                    continue loop;
                }
            }
            
        }
        
        loop : for(int i = 0; i < lost.length; i++) {
            
            int student = lost[i];
            if(student == -1) continue;
            
            for(int j = 0; j < reserve.length; j++) {
                
                if(reserve[j] == -1) continue;
                
                if(reserve[j] - 1 == student || reserve[j] + 1 == student) {
                    answer++;
                    reserve[j] = -1;
                    continue loop;
                }
            }
            
        }
        
        return answer;
    }
}
