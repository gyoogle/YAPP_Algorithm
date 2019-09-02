#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> target;
    
    answer.reserve(commands.size());
    
    for(vector<vector<int>>::size_type i = 0 ; i < commands.size() ; i ++){
        
        int size = commands[i][1] - commands[i][0] + 1;
        
        target.reserve(size);
        copy(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1] , target.begin());
        sort(target.begin(), target.begin() + size);
        answer.push_back(target[commands[i][2] -1]);
        
    }
    
    
    return answer;
}