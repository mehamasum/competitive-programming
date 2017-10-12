package ctci_balanced_brackets;

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static boolean isBalanced(String expression) {
        Stack<Character> stack = new Stack<>();
        for(int i=0; i<expression.length(); i++) {
            //System.out.println(stack);
            char c = expression.charAt(i);
            if(c=='('||c=='{'||c=='[') stack.push(c);
            else if(!stack.isEmpty() && ((c==')' && stack.peek()=='(') || (c==']' && stack.peek()=='[') || (c=='}' && stack.peek()=='{'))) stack.pop();
            else return false;
        }
        return stack.isEmpty();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int a0 = 0; a0 < t; a0++) {
            String expression = in.next();
            System.out.println( (isBalanced(expression)) ? "YES" : "NO" );
        }
    }
}
