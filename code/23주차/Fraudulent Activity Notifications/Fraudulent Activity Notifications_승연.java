import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    static double midean(int[] arr, int d){
        double res=0.0;
        int cnt=0;
        if(d%2 == 0){
            int tmpA =0,tmpB=0;
            for(int i=0;i<arr.length;i++){
                cnt+=arr[i];
                if(tmpA==0&&cnt>=d/2){
                    tmpA = i;
                }
                if(tmpB==0&&cnt>=(d/2)+1){
                    tmpB = i;
                    break;
                }
            }
            res = (tmpA+tmpB)/2.0;
        }
        else{
            for(int i =0;i<arr.length;i++){
                cnt+=arr[i];
                if(cnt>d/2){
                    res = i;
                    break;
                }
            }
        }
        return res;
    }
    // Complete the activityNotifications function below.
    static int activityNotifications(int[] expenditure, int d) {
        int[] arr = new int[201];
        int count=0;
        for(int i=0; i<d;i++){
            arr[expenditure[i]]++;
        }
        for(int i = d;i<expenditure.length;i++){
            double mid = midean(arr, d);
            if(mid*2<=expenditure[i]){
                count++;
            }
            arr[expenditure[i-d]]--;
            arr[expenditure[i]]++;
        }


        return count;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nd = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nd[0]);

        int d = Integer.parseInt(nd[1]);

        int[] expenditure = new int[n];

        String[] expenditureItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int expenditureItem = Integer.parseInt(expenditureItems[i]);
            expenditure[i] = expenditureItem;
        }

        int result = activityNotifications(expenditure, d);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
