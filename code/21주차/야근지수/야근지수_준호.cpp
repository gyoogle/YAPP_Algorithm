#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int i = 50000;
    
    int works_count[50001] = {0,};
    
    for(vector<int>::iterator it = works.begin() ; it != works.end() ; it++){
        works_count[*it] ++;
    }
    
    for(; i > 0 ; i --){
        if(works_count[i] > 0){
            if(works_count[i] < n){
                works_count[i-1] += works_count[i];
                n -= works_count[i];
                works_count[i] = 0;
            }
            else{
                works_count[i - 1] += n;
                works_count[i] -= n;
                break;
            }
        }
    }
    
    for(; i > 0 ; i --){
        for(int j = 0 ; j < works_count[i] ; j ++){
            answer += i * i;
        }
    }
    
    return answer;
}
