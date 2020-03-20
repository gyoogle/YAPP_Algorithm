import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    // Complete the sherlockAndAnagrams function below.
    static int sherlockAndAnagrams(String s) {
        HashMap<Integer,List<String>> hash = new HashMap<>();
        if(s.length()==1) return 0;
        for(int i = 0;i<s.length();i++){
            for(int j= i+1;j<=s.length();j++){
                if(hash.get(j-i)==null){
                    List<String> list = new ArrayList<>();
                    list.add(s.substring(i,j));
                    hash.put(j-i,list);
                }
                else{
                    hash.get(j-i).add(s.substring(i,j));
                }
            }
        }
        int count=0;
        for(Map.Entry<Integer,List<String>> e : hash.entrySet()){
            count += getNum(e.getValue());
        }
        return count;
    }
    static int getNum(List<String> list){
        int count = 0;
        for(int i=0;i<list.size();i++){
            for(int j=i+1; j<list.size();j++){
                if(isPairAnagrams(list.get(i),list.get(j))){
                    count++;
                }
            }
        }
        return count;
    }
    static boolean isPairAnagrams(String s1,String s2){
        char[] arr1 = s1.toCharArray();
        char[] arr2 = s2.toCharArray();
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        s1 = new String(arr1);
        s2 = new String(arr2);
        return s1.equals(s2);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String s = scanner.nextLine();

            int result = sherlockAndAnagrams(s);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
