# 스택 & 큐

### 스택(Stack)

---

> LIFO(Last In First Out) : 후입선출 방식

<img src="https://t1.daumcdn.net/cfile/tistory/225D1F415348EAC132">

데이터의 위치를 알기 위한 `top` 변수 사용

**삽입** : push() / **삭제** : pop()

pop할 데이터가 있는지 여부 : isEmpty()

push할 공간이 있는지 여부 : isFull()

<br>

```java
public class Stack {
    private int MAX_SIZE;
    private int[] stack;
    private int top;

    public Stack() {
        MAX_SIZE = 5;
        stack = new int[MAX_SIZE];
        top = -1;
    }

    private boolean isEmpty() {
        return top == -1 ? true : false;
    }
    private boolean isFull() {
        return (top + 1 == MAX_SIZE) ? true : false;
    }

    public void push(int data) {
        if (!isFull())
            stack[++top] = data;
    }

    public int pop() {
        if (!isEmpty())
            return stack[top--];
        return -1;
    }

    public void display() {
        System.out.print("top : " + top + "\nstack : ");
        for (int idx = 0; idx <= top; idx++)
            System.out.print(stack[idx] + " ");
        System.out.println();
    }
}
```

<br>

<br>

### 큐(Queue)

---

> FIFO(First In First Out) : 선입선출 방식

<img src="https://t1.daumcdn.net/cfile/tistory/242F844853490AC336">

**front** : 데이터를 dequeue 하기 위해 가리키는 인덱스 위치

**rear** : 데이터를 inqueue 하기 위해 가리키는 인덱스 위치

dequeue 할 데이터가 있는지 여부 : isEmpty()

inqueue 할 공간이 있는지 여부 : isFull()

```java
public class Queue {

    private final int MAX_SIZE = 5;
    private int front, rear;
    private int[] queue;

    public Queue() {
        front = rear = -1;
        queue = new int[MAX_SIZE];
    }

    private boolean isEmpty() {
        return front == rear ? true : false;
    }

    private boolean isFull() {
        return rear == MAX_SIZE-1 ? true : false;
    }

    public void enqueue(int data) {
        if (isFull())
            return;
        else
            queue[++rear] = data; //현재 rear 다음 공간에 데이터를 넣는다.
    }

    public int dequeue() {
        if (isEmpty())
            return -1; //데이터가 없어서 dequeue에 실패하면 -1리턴하도록 로직 구현.(임시)
        else
            return queue[++front]; //맨 앞의 데이터를 리턴하고 front를 1증가 시킨다.

    }

    public void display() {
        System.out.print("Queue : ");
        for (int idx = front + 1; idx <= rear; idx++)
            System.out.print(queue[idx] + " ");
    }

}
```

