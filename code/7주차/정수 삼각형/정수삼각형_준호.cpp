#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    
    for(int d = triangle.size() -2 ; d >= 0 ; d --){
        for(int i = 0 ; i < triangle[d].size() ; i ++){
            
            triangle[d][i] += triangle[d +1][i] > triangle[d+1][i+1] ?  triangle[d +1][i] : triangle[d+1][i+1] ;
        }
    }
    
    return triangle[0][0];
}
