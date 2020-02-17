#include <stdio.h>
int N;
int pos = 1;
int arr[11]={0};
void solve(int num){
    while(num > 0){
        arr[num % 10]+= pos;
        num /=10;
    }
}
int main(){
    int start=1;
    int end;
    scanf("%d",&N);
    end = N;
    int i;
    while(start <= end){
        while(start <=end && start%10!=0){
            solve(start);
            start++;
        }
        if(start > end) 
            break;
        while(end%10!=9 && end >= start){
            solve(end);
            end--;
        }
        end = end/10;
        start = start/10;
        
        for(i=0;i<10;i++){
            arr[i] += (end-start+1)*pos;
        }
        pos *=10;
    }
    for(i = 0;i < 10;i++){
        printf("%d ",arr[i]);
    }
   return 0;
}