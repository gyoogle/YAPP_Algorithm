class K번째수 {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        
        for (int i = 0; i < commands.length; i++) {
			
        	int start = commands[i][0] - 1;
        	int end = commands[i][1] - 1;
        	
        	int[] temp = new int[end-start+1];
        	
        	int idx = 0;
        	for (int j = start; j <= end; j++) {
				temp[idx++] = array[j];
			}
            
        	quickSort(temp, 0, temp.length-1);
        	
        	int res = commands[i][2] - 1;
        	
        	answer[i] = temp[res];
		}
        
        return answer;
    }
	
	public static void quickSort(int[] arr, int left, int right) {
		
		if(left >= right) return;
		
		if(left < right) {
			
			int pivot = arr[(left+right)/2];
			int i = left - 1;
			int j = right + 1;
			
			while(true) {
				
				while(arr[++i] < pivot) {
				}
				
				while(arr[--j] > pivot) {
				}
				
				if(i >= j) break;
				
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			
			quickSort(arr, left, i-1);
			quickSort(arr, j+1, right);
			
		}
		
	}
}
