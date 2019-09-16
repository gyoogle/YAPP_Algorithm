class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        int cnt=0;
        int lost1=0;
        for(int i=0;i<lost.length;i++){
            for(int j=0;j<reserve.length;j++){
                if(lost[i]==reserve[j]){
                    lost1++;
                    lost[i]=-1;
                    reserve[j]=-1;
                    break;
                }
            }
        }
        for(int i=0;i<lost.length;i++){
            for(int j=0;j<reserve.length;j++){
                if(lost[i]==reserve[j]+1||lost[i]==reserve[j]-1){
                    cnt++;
                    reserve[j]=-1;
                    break;
                }
            }
        }
        answer=n-lost.length+lost1+cnt;
        return answer;
    }
}