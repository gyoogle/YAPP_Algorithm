package algorithm;

import java.util.ArrayList;

public class ���ʰ� {
	
	public static class minHeap {
			
			private ArrayList<Integer> heap;
			
			// �� ������
			public minHeap() {
				heap = new ArrayList<>();
				heap.add(0); // �ε��� 0 ä��� (1���� �����ϱ� ����)
			}
			
			// ����
			public void insert(int val) {
				heap.add(val);
				int p = heap.size() - 1;
				
				// �� ������ - 1�� 1���� �۾��� ������ ���� -> root�� �̵�
				while(p > 1 && heap.get(p / 2) > heap.get(p)) {
					// �θ𺸴� �ڽ� ��尡 �� ������ �ٲ�� �� (�ּ���)
					int tmp = heap.get(p/2);
					heap.set(p/2, heap.get(p));
					heap.set(p, tmp);
					
					p = p / 2; // p�� �θ� ������ ���� (�θ� ��� �ε����� �̵�)
				}
			}
			
			// ����
			public int delete() {
				
				// �� ������ - 1�� 1���� ������ -1 ����
				if(heap.size()-1 < 1) {
					return -1;
				}
				
				// ������ ���� ��Ʈ �����
				int deleteItem = heap.get(1);
				
				// root�� ���� ������ �� �ְ� ������ �� ����
				heap.set(1, heap.get(heap.size() - 1));
				heap.remove(heap.size()-1);
				
				int pos = 1;
				while((pos * 2) < heap.size()) {
					
					int min = heap.get(pos * 2);
					int minPos = pos * 2;
					
					if (((pos*2 + 1) < heap.size()) && min > heap.get(pos*2 + 1)) {
						min = heap.get(pos*2 + 1);
						minPos = pos * 2 + 1;
					}
					
					if(heap.get(pos) < min)
						break;
					
					// �θ� �ڽ� ��� ��ȯ
					int tmp = heap.get(pos);
					heap.set(pos, heap.get(minPos));
					heap.set(minPos, tmp);
					pos = minPos;
				}
				
				return deleteItem;
			}
	}
	
	static minHeap min;

	public int solution(int[] scoville, int K) {
		
	    int answer = 0;
	    
	    min = new minHeap();
	    
	    for (int i = 0; i < scoville.length; i++) {
	    	min.insert(scoville[i]);
		}
	    
	    while(true) {
	    	
	    	int first = min.delete();
	    	if(first >= K) break;
	    	if(first == -1) {
	    		answer = -1;
	    		break;
	    	}
	    	
	    	int second = min.delete();
	    	if(second == -1) {
	    		answer = -1;
	    		break;
	    	}
	    	
	    	int cal = first+(second*2);
	    	min.insert(cal);
	    	
	    	answer++;
	    }
	    
	    return answer;
	}

}
