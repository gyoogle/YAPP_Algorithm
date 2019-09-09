#include <string>
#include <vector>
#include <math.h>
#include <set>
#include <stdio.h>

using namespace std;

set<int> number_set;

bool isPrime(int number){
    
    if(number <= 1) return false;
    
    int r = (int) sqrt((double)number);
    
    for(int i = 2 ; i < r + 1; i ++){
        if(number % i == 0){
            return false;
        }
    }
    
    
    return true;
}

void makeNumber(string preStr, string subStr){    
    
    string nextPreStr;
    string nextSubStr;
    
    for(int i = 0 ; i < subStr.size() ; i ++){
        nextPreStr = preStr + subStr.substr(i, 1);
        
        number_set.insert(stoi(nextPreStr));
        
        if(subStr.size() > 1){
            nextSubStr = subStr.substr(0,i) + subStr.substr(i + 1, subStr.size() - (i + 1));
            
            makeNumber(nextPreStr, nextSubStr);
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    
    makeNumber("", numbers);
    
    for (set<int>::iterator i = number_set.begin(); i != number_set.end(); ++i){
        
        if(isPrime(*i)){
            answer ++;
        }
        
    }
    
    return answer;
}