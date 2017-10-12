package ctci_bubble_sort;

import java.util.*;

/**
 * Created by mehamasum on 10/11/2017.
 */
public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> arr = new ArrayList<>(n);
        for(int i = 0; i<n; i++) {
            arr.add(sc.nextInt());
        }

        // sort
        int cnt = 0;
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                if(arr.get(j)<arr.get(i)) {
                    Collections.swap(arr, i, j);
                    cnt++;
                }
            }
        }
        System.out.printf("Array is sorted in %d swaps.\n", cnt);
        System.out.printf("First Element: %d\n", arr.get(0));
        System.out.printf("Last Element: %d\n", arr.get(n-1));

    }

}
