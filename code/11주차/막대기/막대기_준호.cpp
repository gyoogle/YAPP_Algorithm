#include <stdio.h>

int main(){
    int x;
    int count = 1;
    int stick = 64;
    scanf("%d", &x);
    
    while(stick != 1){
        if(stick == x){
            break;
        }
        else if(x > stick){
            x = x - stick;
            
            count ++;
        }
        
        
        stick /= 2;
    }
    
    printf("%d",count);
}
