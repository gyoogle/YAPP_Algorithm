import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class 가장먼노드 {
    static ArrayList<Integer>[] list;
	static int[] cnt;
	
	public static int solution(int n, int[][] edge) {
		int answer = 0;
		
		list = new ArrayList[n+1];
		cnt = new int[n+1];
		
		Arrays.fill(cnt, -1);
		cnt[1] = 0;
		
		for (int i = 0; i < edge.length; i++) {
			
			int start = edge[i][0];
			int end = edge[i][1];
			
			if(list[start] == null) {
				list[start] = new ArrayList<>();
			}
			if(list[end] == null) {
				list[end] = new ArrayList<>();
			}
			
			list[start].add(end);
			list[end].add(start);
		}
		
		Queue<Integer> q = new LinkedList<Integer>();
		
		q.add(1);
		
		while(!q.isEmpty()) {
			
			int u = q.poll();
			
			
			for (int i = 0; i < list[u].size(); i++) {
				
				int num = list[u].get(i);
				
				if(cnt[num] == -1) {
					cnt[num] = cnt[u]+1;
					q.add(num);
				}
			}
		}
		
		int max = 0;
		for (int i = 0; i < cnt.length; i++) {
			if(max < cnt[i]) max = cnt[i];
		}
		for (int i = 0; i < cnt.length; i++) {
			if(cnt[i] == max) answer++;
		}
		
		return answer;
	}
}
