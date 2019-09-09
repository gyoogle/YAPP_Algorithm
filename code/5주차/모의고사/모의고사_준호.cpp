#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int soopo[3][10] ={ {1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5} };
    int length[3] = {5,8,10};
    int corect[3] = {0,0,0};
    int max = 0;
    
    for(vector<int>::size_type i = 0 ; i < answers.size() ; i ++){
        for(int j = 0 ; j < 3 ; j ++){
            if(soopo[j][i % length[j]] == answers[i]){
                corect[j] ++;
            } 
        }
    }
    
    for(int i = 0 ; i < 3 ; i ++){
        
        if(corect[i] > max){
            max = corect[i];
        }
    }
    
    for(int i = 0 ; i < 3 ; i ++){
        
        if(corect[i] == max){
            answer.push_back(i + 1);
        }
    }
    
    
    return answer;
}