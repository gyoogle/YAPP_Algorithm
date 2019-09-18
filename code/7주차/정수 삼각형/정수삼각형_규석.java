public class 정수삼각형 {

	public static int solution(int[][] triangle) {
		int answer = 0;
		
		for (int i = triangle.length-1; i > 0; i--) {
			
			for (int j = 0; j < triangle[i].length-1; j++) {
				
				if(triangle[i][j] >= triangle[i][j+1]) {
					triangle[i-1][j] += triangle[i][j];
				}
				else {
					triangle[i-1][j] += triangle[i][j+1];
				}
				
			}
			
		}
		
		answer = triangle[0][0];
		
		return answer;
	}

	public static void main(String[] args) {

		int[][] triangle = {{7}, {3,8}, {8,1,0}, {2,7,4,4}, {4,5,2,6,5}};
		
		System.out.println(solution(triangle));
	}

}
