import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    
    public static int m, n;
    public static int coins[];
    public static long[][] memo;
    public static long dp(int i, int left) {
        if(i>=m) {
            if(left==0) return 1;
            else return 0;
        }
        if(memo[i][left]!=-1) return memo[i][left];
        long ret1=0;
        if(left-coins[i]>=0) ret1=dp(i, left-coins[i]);
        long ret2 = dp(i+1, left);
        //System.out.println(i+" "+left+" :"+ret1+" , "+ret2);
        return memo[i][left] = ret1 + ret2;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        coins = new int[m];
        memo = new long[m][n+1];
        for(int i=0; i<m; i++) for(int j=0; j<n+1; j++) memo[i][j]=-1;
        for(int coins_i=0; coins_i < m; coins_i++){
            coins[coins_i] = in.nextInt();
        }
        System.out.println(dp(0, n));
    }
}
