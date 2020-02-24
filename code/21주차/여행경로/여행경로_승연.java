import java.util.*;
class Solution {
    boolean[] visited;
    int count= 0;
    String route ="";
    List<String> list = new ArrayList<String>();
    public String[] solution(String[][] tickets) {
        visited = new boolean[tickets.length];
        String dept,des;
        for(int i=0;i<tickets.length;i++){
            dept = tickets[i][0];
            des = tickets[i][1];
            if(dept.equals("ICN")){
                visited[i]=true;
                route = dept + ",";
                dfs(tickets,des,1);
                visited[i]=false;
            }
            
        }
        Collections.sort(list);
        
        String[] answer = list.get(0).split(",");
        return answer;
    }
    void dfs(String[][] tickets, String end, int count){
        route += end + ",";
        if(count == tickets.length){
            list.add(route);
            return;
        }
        for(int i =0;i<tickets.length;i++){
            String dept = tickets[i][0];
            String des = tickets[i][1];
            if(dept.equals(end)&&!visited[i]){
                visited[i] = true;
                dfs(tickets,des,count+1);
                visited[i]=false;
                route = route.substring(0,route.length()-4);
            }
        }
        
    }
    
}