import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

public class Solution {

    // Complete the countTriplets function below.
    static long countTriplets(List<Long> arr, long r) {

         Long answer = 0L;
         HashMap<Long,Long> hash1 = new HashMap<>();
         HashMap<Long,Long> hash2 = new HashMap<>();
          for(int i =0;i<arr.size();i++){
            answer += hash2.getOrDefault(arr.get(i),0L);
             if(hash1.containsKey(arr.get(i))){
                 hash2.put(arr.get(i)*r,hash1.get(arr.get(i))+hash2.getOrDefault(arr.get(i)*r,0L));
             }
             hash1.put(arr.get(i)*r,hash1.getOrDefault(arr.get(i)*r,0L)+1);
         }

         return answer;

    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nr = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(nr[0]);

        long r = Long.parseLong(nr[1]);

        List<Long> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Long::parseLong)
            .collect(toList());

        long ans = countTriplets(arr, r);

        bufferedWriter.write(String.valueOf(ans));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
