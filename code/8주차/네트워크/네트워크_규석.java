public class 네트워크 {
	
	static boolean[] Computer;
	
	public static int solution(int n, int[][] computers) {
        
		int answer = 0;
		
		Computer = new boolean[n];
		
		for (int i = 0; i < computers.length; i++) {
			if(!Computer[i]) {
				Computer[i] = true;
				answer++;
			}
			for (int j = 0; j < computers[i].length; j++) {
				if(i == j) continue;
				if(computers[i][j] == 1 && !Computer[j]) {
					dfs(j, computers);
				}
			}
		}
		
		return answer;
    }
	
	public static void dfs(int k, int[][] computers) {
		
		Computer[k] = true;
		
		for (int i = 0; i < Computer.length; i++) {
			if(computers[k][i] == 1 && !Computer[i]) {
				dfs(i, computers);
			}
		}
	}

	public static void main(String[] args) {
		int n = 4;
		
//		int[][] computers = {{1,1,0}, {1,1,1}, {0,1,1}};
		int[][] computers = {{1,0,0,1}, {0,1,0,1}, {0,0,1,0}, {1,1,0,1}};
		
		System.out.println(solution(n, computers));
	}

}
