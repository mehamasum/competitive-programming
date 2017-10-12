package ctci_ransom_note;

/**
 * Created by mehamasum on 10/6/2017.
 */

import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int m = in.nextInt();
        int n = in.nextInt();

        String[] a = new String[m];
        String[] b = new String[n];
        int cnt = 0;

        for(int i=0; i < m; i++){
            a[i] = in.next();
        }

        for(int i=0; i < n; i++){
            b[i] = in.next();
        }

        // soln
        Map <String, Integer> map = new HashMap<>();
        for(String s: a) {
            Integer val = map.get(s);
            if(val==null) {
                map.put(s, 1);
            } else {
                map.put(s, val+1);
            }
        }

        for(String s: b) {
            Integer val = map.get(s);
            if(val==null || val==0) {
                System.out.println("No");
                return;
            }
            else {
                map.put(s, val-1);
            }
        }
        System.out.println("Yes");

    }
}