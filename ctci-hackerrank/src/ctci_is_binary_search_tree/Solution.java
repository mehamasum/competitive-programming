package ctci_is_binary_search_tree;

import java.util.Scanner;

public class Solution {
    class Node {
        int data;
        Node left;
        Node right;
    }
    boolean checkBST(Node root) {
        return bst(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    boolean bst(Node root, int min, int max) {
        if(root==null) return true;
        if(root.data<=min || root.data>=max) return false;
        return bst(root.left, min, root.data) && bst(root.right, root.data, max);
    }
}
