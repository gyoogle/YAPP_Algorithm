import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String[] list = new String[numbers.length];
        for(int i=0;i<numbers.length;i++){
            list[i]=String.valueOf(numbers[i]);
        }
        Arrays.sort(list, (o1,o2)->(o2+o1).compareTo(o1+o2));
        if(list[0].equals("0")){
            return "0";
        }
        StringBuilder str=  new StringBuilder();
        for(int i=0;i<list.length;i++){
           str.append(list[i]);
        }
        return str.toString();
    }
}