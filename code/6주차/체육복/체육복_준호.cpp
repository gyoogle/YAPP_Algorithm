#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    answer = n - lost.size();
    
    for(vector<int>::size_type i = 0 ; i < lost.size() ; i ++){
        for(vector<int>::size_type r = 0 ; r < reserve.size() ; r ++){
            if(lost[i] == reserve[r]){
                answer ++;
                lost.erase(lost.begin() + i , lost.begin() + i + 1);
                reserve.erase(reserve.begin() +r , reserve.begin() + r+ 1);
                i --;
                break;
            }
        }
    }
    
    for(vector<int>::size_type i = 0 ; i < lost.size() ; i ++){
        for(vector<int>::size_type r = 0 ; r < reserve.size() ; r ++){
            if(lost[i] - 1 == reserve[r] || lost[i] + 1 == reserve[r]){
                answer ++;
                reserve.erase(reserve.begin() + r , reserve.begin() +  r + 1);
                break;
            }
        }
    }
    
    return answer;
}