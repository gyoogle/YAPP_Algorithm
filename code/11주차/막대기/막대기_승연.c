#include<stdio.h>

int main(){
    int length;
    int sum=0;
    int num=0;
    int i;
    scanf("%d",&length);
    for(i=64;i>0;i/=2){
        if(i>length){
            continue;
        }
        else if(i==length){
            num=1;
            break;
        }
        if(sum+i<=length){
            sum +=i;
            num++;
        }
    }
    printf("%d",num);
    return 0;
}