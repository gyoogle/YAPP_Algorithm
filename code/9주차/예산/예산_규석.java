import java.util.Arrays;

public class 예산 {
	
	public static int solution(int[] budgets, int M) {
		Arrays.sort(budgets);
		
		int start = 0;
		int end = budgets[budgets.length-1];
		
		while(start <= end) {
			
			int sum = 0;
			int mid = (start+end)/2;
			
			for (int i = 0; i < budgets.length; i++) {
				if(budgets[i] > mid)
					sum+=mid;
				else
					sum+=budgets[i];
			}
			
			if(sum > M)
				end = mid - 1;
			else
				start = mid + 1;
			
		}
		
		
		return end;
	}

	public static void main(String[] args) {
		
		int[] budgets = {130, 130, 130, 130};
		int M = 485;
		
		System.out.println(solution(budgets, M));

	}

}
