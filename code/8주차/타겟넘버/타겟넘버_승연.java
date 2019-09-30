class Solution {
    public int solution(int[] numbers, int target) {
        int answer = 0;
        answer=dfs(numbers,0,0,target);
        
        return answer;
    }
    private int dfs(int[] numbers, int index, int sum, int target){
        if(index==numbers.length){
            if(sum==target){
                return 1;
            }
            else return 0;
        }
        return dfs(numbers,index+1,sum+numbers[index],target)+dfs(numbers,index+1,sum-numbers[index],target);
    }
}