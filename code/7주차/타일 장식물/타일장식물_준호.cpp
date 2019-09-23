#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    
    long long numbers[81];
    
    numbers[0] = 1;
    numbers[1] = 1;
    
    if(N == 1)
        return 4;
    if(N == 2)
        return 6;
    
    for(int i = 2 ; i < N ; i ++){
        numbers[i] = numbers[i-1] + numbers[i-2];
    }
    
    return (numbers[N-1] + numbers[N-2]) * 2 +  (numbers[N-3] + numbers[N-2]) * 2;
}