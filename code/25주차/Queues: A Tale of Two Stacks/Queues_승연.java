import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static void main(String[] args) {
         class MyQueue<T>{
            Stack<T> stack1 = new Stack<>();
            Stack<T> stack2 = new Stack<>();
            public void enqueue(T value){
                stack1.push(value);
            }
            public T dequeue(){
                transfer();
                return stack2.pop();
            }
            public T peek(){
                transfer();
                return stack2.peek();
            }
            public void transfer(){
                if(!stack2.empty()) return;
                while(!stack1.empty()){
                    stack2.push(stack1.pop());
                }
            }

        }
        MyQueue<Integer> queue = new MyQueue<Integer>();

        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        for (int i = 0; i < n; i++) {
            int operation = scan.nextInt();
            if (operation == 1) { // enqueue
              queue.enqueue(scan.nextInt());
            } else if (operation == 2) { // dequeue
              queue.dequeue();
            } else if (operation == 3) { // print/peek
              System.out.println(queue.peek());
            }
        }
        scan.close();
    }
}