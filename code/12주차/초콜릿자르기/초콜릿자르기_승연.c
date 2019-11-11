#include<stdio.h>
int main(){
    int M,N;
    int num=0;
    scanf("%d %d",&M,&N);
    num = (N-1)+N*(M-1);
    printf("%d",num);
    return 0;
}