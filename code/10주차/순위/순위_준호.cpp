#include <string>
#include <vector>
#include <set>
#include <stdio.h>

using namespace std;

set<int> * dfs(int node, vector<vector<int>> * cur_graph, vector<set<int> *> * cur_sets){
    if(! (*cur_sets)[node]){
        set<int> * set_from_other ;
        set<int> * cur_set ;
        vector<int> cur_edges ;
        
        (*cur_sets)[node] = new set<int>();
        
        cur_set = (*cur_sets)[node];
        
        cur_edges = (*cur_graph)[node];
        
        for(vector<vector<int>> ::size_type i = 0 ;i < cur_edges.size(); i ++){
            int next_node = (cur_edges)[i];
            
            set_from_other = dfs(next_node, cur_graph, cur_sets);
            
            cur_set -> insert(set_from_other -> begin(), set_from_other -> end());
            
            cur_set -> insert(next_node);
        }   
    
    }
    
    
    return (*cur_sets)[node];
    
}

int solution(int n, vector<vector<int>> results) {
    
    int answer = 0;
    
    vector<vector<int>> up_graph, down_graph;
    vector<set<int> *> up_sets(n, nullptr), down_sets(n,  nullptr);
    
    //init
    
    up_graph.reserve(n);
    down_graph.reserve(n);
    
    for(int  i = 0 ; i < n ; i ++){
        vector<int> up_edge,down_edge;
        up_graph.push_back(up_edge);
        down_graph.push_back(down_edge);
    }
    
    
    
    for(vector<vector<int>>::size_type i = 0 ; i < results.size() ; i ++){
        
        int up, down;
        up = results[i][0] - 1;
        down = results[i][1] - 1;
        //printf("%d %d\n", up, down);
        up_graph[up].push_back(down);
        down_graph[down].push_back(up);
    }
    
    
    //contents
    
    for(int i = 0 ; i < n ; i ++){
        dfs(i, &up_graph, &up_sets);
        dfs(i, &down_graph, &down_sets);
    }
    
    
    for(int i = 0 ; i < n ; i ++){
        int up_size , down_size;
        if(up_sets[i] && down_sets[i]){
            up_size = up_sets[i] -> size();
            down_size = down_sets[i] -> size();


            if(up_size + down_size == n -1){
                answer ++;
            }
        }

    }
    
    
    
    
    return answer;
}
