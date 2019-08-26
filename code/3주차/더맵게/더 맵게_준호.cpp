#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    long a,b = 0;
    
    priority_queue<long,vector<long>,greater<long>> scoville_pq;
    
    for(vector<long>::size_type i = 0; i < scoville.size() ; i ++){
        scoville_pq.push((long) scoville[i]);
    }
    

    
    while(scoville_pq.size() >= 2){
        
        a = scoville_pq.top();
        scoville_pq.pop();
        
        b = scoville_pq.top();
        scoville_pq.pop();
        
        if(a >= (long) K && b >= (long) K){
            break;
        }
        
        scoville_pq.push(a + b*2);
        
        answer ++;
    }
    
    if(scoville_pq.top() < (long) K){
        return -1;
    }
    else{
        return answer;
    }
}