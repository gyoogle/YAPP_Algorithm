#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

typedef vector<string> EDGES;
typedef unordered_map<string ,EDGES >  GRAPH;
typedef unordered_map<string, vector<int>> VISITED ;

void push_edge_to_graph(GRAPH& graph , VISITED& visted, vector<string> edge){
    string start,end;
    start = edge[0];
    end = edge[1];
    
    visted[start].push_back(0);

    if(graph[start].empty()){
        graph[start].push_back(end);
    }
    else{
        for(vector<string>::iterator it = graph[start].begin() ; it != graph[start].end() ; it ++){
            if(end < *it){
                graph[start].insert(it, end);
                return;
            }
        }
        graph[start].push_back(end);
    }
    
    
}

bool DFS(int size , string start, GRAPH& graph, VISITED& visted, vector<string>& route){
    if(size == 0){
        return true;
    }
    else{
        EDGES next = graph[start] ;
        vector<int>& cur_visted = visted[start];
        
        for(int i = 0 ; i < next.size(); i ++){
            if(cur_visted[i] == 0) {
                bool result;
                cur_visted[i] = 1;
                route.push_back(next[i]);
                result = DFS(size -1 , next[i], graph, visted, route);
                
                if(result){
                    return true;
                }
                else{
                    route.pop_back();
                    cur_visted[i] = 0;
                }
            }
        }
        
        return false;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    GRAPH graph;
    VISITED visted;
    
    for(vector<vector<string>>::iterator it = tickets.begin() ; it != tickets.end() ; it ++){
        push_edge_to_graph(graph, visted, *it);
    }
    
    answer.push_back("ICN");
    
    DFS(tickets.size(), "ICN", graph, visted, answer);
    
    return answer;
}
