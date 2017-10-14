import java.util.*;

public class Solution {

	private static int[] arr;
    public static int fibonacci(int n) {
    	if(n==0||n==1) return n;
    	if(arr[n]!=0) return arr[n];
    	return arr[n]=fibonacci(n-1)+fibonacci(n-2);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        arr = new int[n+1];
        scanner.close();
        System.out.println(fibonacci(n));
    }
}