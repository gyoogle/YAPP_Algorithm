#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <stdio.h>

using namespace std;

int solution(string name) {
    int answer = 0;
    char cstr[21] ;
    int ptr = 0;
    int min_lr = 0, min_ptr= 0;
    char cur_char ;
    int cur_updown, cur_lr, cur_move;
    int times = name.size();;
    
    strcpy(cstr, name.c_str());
    cur_char = 'A';
    ptr = 0;
    
    for(int i = 0 ; i < name.size() ; i ++){
        if(cstr[i] == 'A'){
            cstr[i] = '*';
            times --;
        }
    }
    
    for(int count = 0 ; count < times; count ++){
        
        min_lr = 100, min_ptr= 0;
        
        
        for(int i = 0 ; i < name.size() ; i ++){
            if(cstr[i] == '*')
                continue;
            
            cur_lr = abs(ptr - i);
            
            if(cur_lr > name.size() / 2){
                cur_lr = name.size() - cur_lr;
            }
            
            if(min_lr > cur_lr){
                min_lr = cur_lr;
                min_ptr = i;
            }
        }       
        
        cur_updown = abs(cur_char - cstr[min_ptr]);
            
        if(cur_updown > 13){
            cur_updown = 26 - cur_updown ;
        }
        
        answer += min_lr + cur_updown;
        ptr = min_ptr;
        
        cstr[ptr] = '*';
    }
    
    return answer;
}