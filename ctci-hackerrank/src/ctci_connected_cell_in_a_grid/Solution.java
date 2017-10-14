package ctci_connected_cell_in_a_grid;
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static int n, m;
    public static int[][] grid, color;

    public static int[] dirX = {-1, -1, -1, 0, 0, 1, 1, 1};
    public static int[] dirY = {-1,  0,  1, -1, 1, -1, 0, 1};

    public static int DFS(int i, int j) {
        color[i][j] = 1;
        int ret = 1;
        for(int k=0; k<8; k++) {
            try {
                int ii = i + dirX[k];
                int jj = j+dirY[k];
                //System.out.println(">"+ii+" "+jj);
                if (color[ii][jj] == 0 && grid[ii][jj]==1) {
                    //System.out.println(">>"+ii+" "+jj);
                    ret+=DFS(ii, jj);
                }
            }
            catch (ArrayIndexOutOfBoundsException e) {
                //ignore
            }
        }
        color[i][j] = 2;
        //System.out.println(i+" "+j+" -> "+ret);
        return ret;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        grid = new int[n][m];
        color= new int[n][m];
        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++){
                grid[i][j] = in.nextInt();
                color[i][j] = 0;
            }
        }

        int ans = 0;
        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++){
                if(grid[i][j]==1 && color[i][j]==0) {
                    ans = Math.max(ans, DFS(i, j));
                    //System.out.println(ans);
                }
            }
        }
        System.out.println(ans);

    }
}
