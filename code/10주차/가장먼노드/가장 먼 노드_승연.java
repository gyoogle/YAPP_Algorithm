import java.util.*;
 
class Solution {
    public int solution(int n, int[][] edge) {
        ArrayList<ArrayList<Integer>> list = new <ArrayList<Integer>> ArrayList();
        Queue<Integer> q = new LinkedList<Integer>();
        for(int i = 0; i < edge.length; i++) {
            list.add(new ArrayList<Integer>()); 
        }
        for(int i = 0; i < edge.length; i++) {
            int m = edge[i][0];
            int h = edge[i][1];
            list.get(m).add(h);
            list.get(h).add(m);
        }
 
        int[] d = new int[n+1];
        Arrays.fill(d, -1);
        
        d[1] = 0;
        q.add(1);
        int u = 0;
        while(q.size() > 0) {
            u = q.poll();
            for(int e : list.get(u)) {
                if(d[e] == -1) {
                    d[e] = d[u]+1;
                    q.add(e);
                }
            }
            
        }
        
        int count = 0;
        int max = d[0];
        for(int i : d) {
            if(max < i) {
                max = i;
                count = 1;
            }else if(max == i){
                count++;
            }
        }
        return count;
    }
}
