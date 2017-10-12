package ctci_linked_list_cycle;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by mehamasum on 10/11/2017.
 */
public class Solution {

    static class Node {
        int data;
        Node next;
    }

    static boolean hasCycle(Node head) {
        Map<Node, Boolean> map = new HashMap<>();
        Node node = head;
        while (node!=null) {
            Boolean stored = map.get(node);
            if(stored==null) map.put(node, true);
            else if(stored) return true;
            node = node.next;
        }

        return false;
    }

    public static void main(String[] args) {
        Node head = new Node();
        head.data = 5;

        Node one = new Node();
        one.data = 1;


        Node two = new Node();
        two.data = 2;

        head.next = one;
        one.next = two;
        two.next = null;

        System.out.println(hasCycle(head));

    }

}
