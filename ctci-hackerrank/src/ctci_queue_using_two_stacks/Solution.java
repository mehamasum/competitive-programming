package ctci_queue_using_two_stacks;

import java.util.Scanner;
import java.util.Stack;

public class Solution {
    static class MyQueue {
        Stack<Integer> inbox = new Stack<>();
        Stack<Integer> outbox = new Stack<>();

        void enqueue(int x) {
            inbox.push(x);
        }

        void dequeue() {
            if(outbox.isEmpty()) {
                while (!inbox.isEmpty())
                    outbox.push(inbox.pop());
            }
            if(!outbox.isEmpty()) outbox.pop();
        }

        int peek() {
            if(outbox.isEmpty()) {
                while (!inbox.isEmpty())
                    outbox.push(inbox.pop());
            }
            if(!outbox.isEmpty()) return outbox.peek();
            return -1;
        }
    }


    public static void main(String[] args) {
        MyQueue queue = new MyQueue();

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
