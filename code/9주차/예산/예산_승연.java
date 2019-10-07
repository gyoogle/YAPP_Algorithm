import java.util.Arrays;
class Solution {
    public int solution(int[] budgets, int M) {
        int answer = 0;
         Arrays.sort(budgets);
        int start = 0, end = budgets[budgets.length - 1];
        while(start <= end)
        {
            int sum = 0;
            int mid = (start + end) / 2;
            for(int element : budgets)
                sum = element > mid ? sum + mid : sum + element;
            if(sum > M) end = mid - 1;
            else
                start = mid + 1;
        }
        return end;
    }
    
}