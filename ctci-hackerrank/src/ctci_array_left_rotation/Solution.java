package ctci_array_left_rotation;

/**
 * Created by mehamasum on 10/6/2017.
 */

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();

        int[] a = new int[n];
        int[] b = new int[n];
        int cnt = 0;

        for(int i=0; i < n; i++){
            a[i] = in.nextInt();
        }

        // soln
        for(int i=k; i<n; i++) {
            b[cnt++] = a[i];
        }
        for(int i=0; i<k; i++) {
            b[cnt++] = a[i];
        }

        for(int i=0; i < n; i++){
            System.out.print(b[i]);
            if(i<n) System.out.print(" ");
        }

    }
}