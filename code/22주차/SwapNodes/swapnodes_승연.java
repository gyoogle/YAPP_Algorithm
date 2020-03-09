import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {
    static class Node{
        int number;
        int depth;
        Node left;
        Node right;

        public Node(int number, int depth, Node left, Node right){
            this.number = number;
            this.depth = depth;
            this.left = left;
            this.right = right;
        }
    } 
    static void inorder(Node nodes,List<Integer> list){
        if(nodes==null) return;
        inorder(nodes.left,list);
        list.add(nodes.number);
        inorder(nodes.right,list);
        
    }
    static void swap(Node nodes, int depth,int k){
        if(nodes==null){
            return;
        }
        swap(nodes.left,depth+1,k);
        swap(nodes.right,depth+1,k);

        if(k<=depth && depth%k==0){
            Node tmp = nodes.left;
            nodes.left = nodes.right;
            nodes.right = tmp;
        }
    }
    static int[][] swapNodes(int[][] indexes, int[] queries) {
        int ilength = indexes.length;
        int qlength = queries.length;
        int[][] answer = new int[qlength][ilength];

        Node root = new Node(1,1,null,null);
        Node current = root;
        Queue<Node> queue = new LinkedList<Node>();
        queue.offer(current);
        for(int i=0;i<ilength;i++){
            current = queue.poll();
            int leftnode = indexes[i][0];
            int rightnode = indexes[i][1];
            if(leftnode==-1){
                current.left = null;
            }
            else{
                current.left = new Node(leftnode,current.depth+1,null,null);
            }
            if(rightnode==-1){
                current.right = null;
            }
            else{
                current.right = new Node(rightnode,current.depth+1,null,null);
            }
            if(current.left!=null&&current.left.number!=-1){
                queue.offer(current.left);
            }
            if(current.right!=null&&current.right.number!=-1){
                queue.offer(current.right);
            }
        }
        for(int i =0;i<qlength;i++){
            swap(root,1,queries[i]);
            List<Integer> list = new ArrayList<>();
            inorder(root,list);
            answer[i]=list.stream().mapToInt(l -> l).toArray();
        }
        return answer;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(scanner.nextLine().trim());

        int[][] indexes = new int[n][2];

        for (int indexesRowItr = 0; indexesRowItr < n; indexesRowItr++) {
            String[] indexesRowItems = scanner.nextLine().split(" ");

            for (int indexesColumnItr = 0; indexesColumnItr < 2; indexesColumnItr++) {
                int indexesItem = Integer.parseInt(indexesRowItems[indexesColumnItr].trim());
                indexes[indexesRowItr][indexesColumnItr] = indexesItem;
            }
        }

        int queriesCount = Integer.parseInt(scanner.nextLine().trim());

        int[] queries = new int[queriesCount];

        for (int queriesItr = 0; queriesItr < queriesCount; queriesItr++) {
            int queriesItem = Integer.parseInt(scanner.nextLine().trim());
            queries[queriesItr] = queriesItem;
        }

        int[][] result = swapNodes(indexes, queries);

        for (int resultRowItr = 0; resultRowItr < result.length; resultRowItr++) {
            for (int resultColumnItr = 0; resultColumnItr < result[resultRowItr].length; resultColumnItr++) {
                bufferedWriter.write(String.valueOf(result[resultRowItr][resultColumnItr]));

                if (resultColumnItr != result[resultRowItr].length - 1) {
                    bufferedWriter.write(" ");
                }
            }

            if (resultRowItr != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();
    }
}