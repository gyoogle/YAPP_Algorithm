import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the twoStrings function below.
    static String twoStrings(String s1, String s2) {
        String[] arrs1 = s1.split("");
        String[] arrs2 = s2.split("");
        HashMap<String, Integer> hash = new HashMap<>();
        for(String s : arrs1){
            if(!hash.containsKey(String.valueOf(s))){
                hash.put(String.valueOf(s),1);
            }else{
                hash.put(String.valueOf(s),hash.get(String.valueOf(s))+1);
            }
        }
        int count = 0;
        for(String s : arrs2){
            if(hash.containsKey(String.valueOf(s))){
                int val = hash.get(String.valueOf(s));
                if(val > 0){
                    count++;
                    val = val - 1;
                    hash.put(String.valueOf(s),val);
                }
            }
        }
        if(count>0){
            return "YES";
        }
        else{
            return "NO";
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String s1 = scanner.nextLine();

            String s2 = scanner.nextLine();

            String result = twoStrings(s1, s2);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
