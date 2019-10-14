#include <string>
#include <vector>

using namespace std;

class Node{
public :
    int parent;
};

int findRoot(Node nodes[], int target){
    
    if(target == nodes[target].parent){
        return target;
    }
    else{
        return findRoot(nodes, nodes[target].parent);
    }   
}

bool union_find(int n, vector<vector<int>> * edges , int victim){
    Node node[5000];
    
    for(int i = 0 ; i < 5000 ; i ++){
        node[i].parent = i;
    }
    
    for(vector<vector<int>> ::size_type i = 0 ;  i < edges -> size() ; i ++)
    {        
        int p , q, rootP, rootQ;
        
        p = (*edges)[i][0] -1 ;
        q = (*edges)[i][1] -1 ;
        
        if(p == victim || q == victim)
            continue;
        
        
        rootP = findRoot(node,p);
        rootQ = findRoot(node,q) ;
        
        if(rootP == rootQ){
            return false;
        }
        
        node[rootP].parent = rootQ;
        

        
    }
    
    return true;
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    
    for(int i = 0 ; i < n; i ++){
        if(union_find(n, &edges, i)){
            answer += (i +1);
        }
            
    }
    
    return answer;
}
