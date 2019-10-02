public class 입국심사 {
	
    static long answer = Long.MAX_VALUE;
	
	public static long solution(int n, int[] times) {

		long max = Long.MIN_VALUE;
        
        for (int i = 0; i < times.length; i++) {
			if(max < times[i]) max = times[i];
		}
        
        long start = 1;
        long end = max*n;
        long mid = 0;
        
        while(start <= end) {
        	
        	mid = (start+end)/2;
        	int count = 0;
        	
        	for (int i = 0; i < times.length; i++) {
				if(times[i] > mid) continue; // 심사시간이 mid보다 크면 넘김
				count += mid/times[i];
			}
        	
        	if(count < n) {
        		start = mid + 1;
        	}
        	else if(count >= n) {
        		end = mid - 1;
        		answer = (answer < mid) ? answer : mid; 
        	}
        }
        
        return answer;
    }
	public static void main(String[] args) {
		int n = 3;
		int[] times = {1,2,3};
		
		System.out.println(solution(n, times));
	}

}
