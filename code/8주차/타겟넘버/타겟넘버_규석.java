class 타겟넘버 {
    static int cnt;
	
	public static int solution(int[] numbers, int target) {
        
        cnt = 0;
        
        dfs(0, 0, numbers, target);
        
        return cnt;
    }
	
	public static void dfs(int len, int sum, int[] numbers, int target) {
		
		if(len >= numbers.length) {
			if(sum == target) cnt++;
			return;
		}
		
		dfs(len+1, sum+numbers[len], numbers, target);
		dfs(len+1, sum+(-numbers[len]), numbers, target);
		
	}
}
