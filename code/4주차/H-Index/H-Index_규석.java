
public class H_Index {
	
	public static int solution(int[] citations) {
        int answer = 0;
        
        quickSort(citations, 0, citations.length-1);
        
        int res = citations[citations.length-1];
        
        while(res >= 0) {
        	
        	int cnt = 0;
        	
        	for (int i = 0; i < citations.length; i++) {
				if(citations[i] >= res) cnt++;
			}
        	
        	if(res <= cnt) {
        		answer = res;
        		break;
        	}
        	
        	res--;
        }
        
        return answer;
    }
	
	public static void quickSort(int[] citations, int start, int end) {
		
		if(start >= end) return;
		
		if(start < end) {
			
			int i = start-1;
			int j = end+1;
			int pivot = citations[(start+end)/2];
			
			while(true) {
				
				while(citations[++i] < pivot) {}
				while(citations[--j] > pivot) {}
				
				if(i>=j) break;
				
				int temp = citations[i];
				citations[i] = citations[j];
				citations[j] = temp;
			}
			
			quickSort(citations, start, i-1);
			quickSort(citations, j+1, end);
			
		}
		
	}

	public static void main(String[] args) {

		int[] arr = {1, 2, 3, 3, 3, 3, 4, 4, 5, 6, 7, 7, 8, 8, 9, 9, 10, 10, 10};
		
		System.out.println(solution(arr));
	}

}
