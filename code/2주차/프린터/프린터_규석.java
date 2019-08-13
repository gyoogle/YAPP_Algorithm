public class 프린터_규석 {
	
	static int idx = 1; // 반환값으로 전달할 인덱스 값
	static int leng; // 인쇄할때마다 바뀌는 priorities의 길이
	
	// Queue 구현
	static class Queue {
		static int front;
		static int rear;
		static int[] queue;
		static int max;
		
		Queue(int size) {
			front = 0;
			rear = 0;
			max = size+1;
			queue = new int[size+1];
		}
		
		static boolean isEmpty() {
			return (front == rear);
		}
		
		static boolean isFull() {
			if((rear+1) % max == front)
				return true;
			else
				return false;
		}
		
		static boolean enQueue(int n) {
			if(isFull()) {
				return false; 
			}
			
			queue[rear] = n;
			rear++;
			if(rear == max) rear = 0;
			
			return true;
		}
		
		static Integer deQueue() {
			
			if(isEmpty()) {
				return -1;
			}
			
			int val = queue[front];
			front++;
			if(front == max) front = 0;
			
			return val;
		}
		
	}
	
		
    public static int solution(int[] priorities, int location) {
        int answer = 0;
        
        leng = priorities.length; // priorities의 길이를 leng에 저장
        
        Queue queue = new Queue(priorities.length); // 큐 생성
        
        for (int i = 1; i <= priorities.length; i++) {
			queue.enQueue(i); // priorities의 길이만큼 큐에 인쇄할 고유 숫자 넣기 (1, 2, 3, 4 ... )
		}
        
        while(true) { // 큐 사이즈가 비어있을 때까지 반복
        	
        	int num = queue.deQueue(); // 하나 뺌
        	if (num == -1) break; // 만약 비어있어서 -1이 리턴되면 반복문 break
        	
        	int priority = priorities[0]; // 현재 큐에서 뺀 인쇄물의 우선순위
        	
        	boolean chk = true;
        	
        	for (int i = 1; i < priorities.length; i++) {
        		
				if(priority < priorities[i]) { // 더 큰 우선순위가 있으면 뒤로 붙여야 함
					queue.enQueue(num); // 뽑은 수를 다시 넣기
					rotation(priorities); // 우선순위도 rotate
					chk = false;
					break;
				}
			}
        	
        	if(chk) { // 더 큰 우선순위가 없는 상황 (해당 번호 인쇄해야함)
        		
        		if(num == location+1) { // 만약 뽑은 수와 location으로 들어온 수가 일치하면 내가 원하는 답
        			answer = idx; // 현재 인덱스 값을 answer에 저장하고 break
        			break;
        		}
        		
        		// 일치하지 않으면 다음 인쇄를 진행해야 한다.
        		
        		rotation(priorities); // 우선순위 rotate
        		priorities[leng - 1] = 0; // 우선순위에 저장된 마지막 값을 0으로 없애버림
        		leng--; // 길이를 하나 줄여줌
            	idx++; // 인덱스 값 하나 늘려줌
        	}
        	
        }        
        return answer;
    }
    
    
    // rotation 함수 구현 (첫번째 인덱스 값을 끝으로 보내고, 하나씩 앞으로 땡긴다)
    // ex. (1 2 3 4) -> (2 3 4 1)
    public static void rotation(int[] arr) {
    	int temp = arr[0];
    	
    	for (int i = 0; i < leng - 1; i++) {
			arr[i] = arr[i+1];
		}
    	
    	arr[leng-1] = temp;
    }
    
    public static void main(String[] args) {
		
    	int[] priorities = {2, 2, 2, 1, 3, 4};
    	int location = 3;
    	
    	int num = solution(priorities, location);
    	System.out.println(num);
	}

}
