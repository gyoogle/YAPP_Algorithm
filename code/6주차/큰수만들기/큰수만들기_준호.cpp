#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    
    for(int count = 0 ; count < k ; count ++){
        int victim = number.length() - 1;
        
        for(int i = 0 ; i < number.length() -1; i ++){
            if(number.at(i) < number.at(i +1)){
                
                victim = i;
                break;
            }
        }
        
        number = number.erase(victim , 1);
        
    }
    return number;
}