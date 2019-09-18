public class 타일장식물 {
	
	static long[] sum;
	
	public long solution(int N) {
        long answer = 0;
        
        sum = new long[N+1];
        
        sum[1] = sum[2] = 1;
        
        for (int i = 3; i < sum.length; i++) {
			sum[i] = sum[i-1] + sum[i-2];
		}
        
        answer = sum[N]*2 + (sum[N]+sum[N-1])*2;
        
        return answer;
    }

}
