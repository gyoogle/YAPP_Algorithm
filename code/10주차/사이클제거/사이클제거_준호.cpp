#include <string>
#include <vector>
#include <string.h>
#include <stack>

using namespace std;

void get_cycle(int node, vector<vector<int>> graph, vector<stack<int> *> * cycle , stack<int> path, int * visited){
      
    visited[node] = 1;

    
   // printf("node is %d\n", node );
    
    for(int i = 0 ; i < graph[node].size() ; i ++){
        
        
        int next = graph[node][i];
        
        
          //  printf("  node is %d  nei is %d\n", node,next);
        
        if(visited[next] == 0){
            path.push(node);
            get_cycle(next, graph, cycle, path, visited);
            path.pop();
        }
        else{
            stack<int> * cur_cycle = new stack<int>();
            
            
            cur_cycle -> push(node);
         //   printf("%d ", cur_cycle->top());

            
            if(!path.empty()){
                
                cur_cycle -> push(path.top());
                path.pop();
          //      printf("%d ", cur_cycle->top());
            }

            bool detected = false;

            while(! path.empty()){

                cur_cycle -> push(path.top());
                path.pop();
                
            //    printf("%d ", cur_cycle->top());

                if(cur_cycle ->top() == next){
                //    printf("cycle detected\n");
                    
                    stack<int> * target = new stack<int>(*cur_cycle);
                    
                    cycle -> push_back(target);
                    
                    detected = true;
                }
            }
          //  printf("\n");


            while(!cur_cycle->empty()){
                path.push(cur_cycle->top());
                cur_cycle->pop();
            }

            if(!path.empty()){
                path.pop();
            }

            delete cur_cycle;
            cur_cycle = nullptr;


        }
        

    }
    
    
    
    return;
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    
    int visited[5005];    
    stack<int> path ;    
    vector<stack<int> *> cycle;
    vector<vector<int>> graph ;
    
    memset(visited, 0 , sizeof(visited));
    
    graph.reserve(n + 10);
    
    for(int i = 0 ; i < n + 10 ; i ++){
        vector<int> v;
        graph.push_back(v);
    }
    
    
    for(int i = 0 ; i < edges.size(); i ++){
        int p , q;
        
        p = edges[i][0];
        q = edges[i][1];
        
        graph[p].push_back(q);
        graph[q].push_back(p);
    }

    
    for(int i = 1 ; i <= n ;i  ++){
        
        if(visited[i] == 0){            
            get_cycle(i, graph, &cycle, path, visited);
        }
    }
    
   // printf("\ncycle size : %d \n", cycle.size());
    
    vector<vector<int>> cycle_checked;
    
    cycle_checked.reserve(cycle.size());
    
    
    vector<int> nodes_checked(n + 10,0);
    int count  =0;
    
    for(int i =  0; i < cycle.size() ; i ++){
        count ++;
        vector<int> cur_checked(edges.size(),0);
        
        int start, p,q;
        
        start = p = cycle[i] -> top();
        cycle[i] -> pop();
        
        while(!cycle[i]->empty()){            
            q = cycle[i] -> top();
            for(int i = 0 ; i < edges.size() ; i ++){
                if((p == edges[i][0] && q == edges[i][1]) ||
                    (q == edges[i][0] && p == edges[i][1] )){
                    cur_checked[i] = 1;
                    
                    
                    nodes_checked[p] ++;
                    nodes_checked[q] ++;
                    break;
                }
            }
            cycle[i] ->pop();
            
            p = q;
            
            
            
        }
        
        q = start;
        
        for(int i = 0 ; i < edges.size() ; i ++){
            if((p == edges[i][0] && q == edges[i][1]) ||
                (q == edges[i][0] && p == edges[i][1] )){
                cur_checked[i] = 1;
                
                nodes_checked[p] ++;
                nodes_checked[q] ++;
                break;
            }
        }
        
       // printf("\n");
        
        cycle_checked.push_back(cur_checked);
    }
    

    
    for(int i = 0 ; i < cycle_checked.size() - 1 ; i ++){
        for(int j = i + 1 ; j < cycle_checked.size(); j ++){
            count ++;
            
            vector<int> i_checked = cycle_checked[i];
            vector<int> j_checked = cycle_checked[j];
            
            for(int ptr =0 ; ptr < edges.size() ; ptr ++){
                //printf("%d ", i_checked[ptr] ^ j_checked[ptr]);
                if(i_checked[ptr] ^ j_checked[ptr] == 1){
                    int p = edges[ptr][0];
                    int q = edges[ptr][1];
                    
                    nodes_checked[p] ++ ;
                    nodes_checked[q] ++;
                }
                
            }
           // printf("\n");
        }
    }
   // printf("count %d \n", count);
    
    for(int i = 0 ; i < nodes_checked.size() ; i ++){
      //  printf("%d : %d - ",i, nodes_checked[i]);
        if(nodes_checked[i] >= count * 2){
            answer += i;
           // printf("can deleted");
        }
        
       // printf("\n");
    }
    
    
    return answer;
}
