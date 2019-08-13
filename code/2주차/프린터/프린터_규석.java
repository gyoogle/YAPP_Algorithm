public class ������_�Լ� {
	
	static int idx = 1; // ��ȯ������ ������ �ε��� ��
	static int leng; // �μ��Ҷ����� �ٲ�� priorities�� ����
	
	// Queue ����
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
        
        leng = priorities.length; // priorities�� ���̸� leng�� ����
        
        Queue queue = new Queue(priorities.length); // ť ����
        
        for (int i = 1; i <= priorities.length; i++) {
			queue.enQueue(i); // priorities�� ���̸�ŭ ť�� �μ��� ���� ���� �ֱ� (1, 2, 3, 4 ... )
		}
        
        while(true) { // ť ����� ������� ������ �ݺ�
        	
        	int num = queue.deQueue(); // �ϳ� ��
        	if (num == -1) break; // ���� ����־ -1�� ���ϵǸ� �ݺ��� break
        	
        	int priority = priorities[0]; // ���� ť���� �� �μ⹰�� �켱����
        	
        	boolean chk = true;
        	
        	for (int i = 1; i < priorities.length; i++) {
        		
				if(priority < priorities[i]) { // �� ū �켱������ ������ �ڷ� �ٿ��� ��
					queue.enQueue(num); // ���� ���� �ٽ� �ֱ�
					rotation(priorities); // �켱������ rotate
					chk = false;
					break;
				}
			}
        	
        	if(chk) { // �� ū �켱������ ���� ��Ȳ (�ش� ��ȣ �μ��ؾ���)
        		
        		if(num == location+1) { // ���� ���� ���� location���� ���� ���� ��ġ�ϸ� ���� ���ϴ� ��
        			answer = idx; // ���� �ε��� ���� answer�� �����ϰ� break
        			break;
        		}
        		
        		// ��ġ���� ������ ���� �μ⸦ �����ؾ� �Ѵ�.
        		
        		rotation(priorities); // �켱���� rotate
        		priorities[leng - 1] = 0; // �켱������ ����� ������ ���� 0���� ���ֹ���
        		leng--; // ���̸� �ϳ� �ٿ���
            	idx++; // �ε��� �� �ϳ� �÷���
        	}
        	
        }        
        return answer;
    }
    
    
    // rotation �Լ� ���� (ù��° �ε��� ���� ������ ������, �ϳ��� ������ �����)
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
