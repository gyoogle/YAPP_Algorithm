import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the abbreviation function below.
    static String abbreviation(String a, String b) {
        boolean[][] dp = new boolean[b.length()+1][a.length()+1];
        dp[0][0] = true;
        for(int i = 1;i <a.length()+1;i++){
            if(Character.isLowerCase(a.charAt(i-1))){
                dp[0][i]=dp[0][i-1];
            }
        }
        for(int i=1;i<b.length()+1;i++){
            char cb = b.charAt(i-1);
            for(int j=1;j<a.length()+1;j++){
                char ca = a.charAt(j-1);
                if(ca>='A'&&ca<='Z'){
                    if(ca==cb){
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
                else{
                    if(Character.toUpperCase(ca)==cb){
                        dp[i][j] = dp[i-1][j-1]||dp[i][j-1];
                    }else{
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }
        return dp[b.length()][a.length()]?"YES":"NO";
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String a = scanner.nextLine();

            String b = scanner.nextLine();

            String result = abbreviation(a, b);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
