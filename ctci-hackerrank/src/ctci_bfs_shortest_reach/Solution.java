package ctci_bfs_shortest_reach;

import java.util.*;

/**
 * Created by mehamasum on 10/11/2017.
 */
public class Solution {
    public static int v, e;

    public static int[] bfs(ArrayList<Integer>[] g, int s) {
        int[] d = new int[v+1];
        int[] vis = new int[v+1];

        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        d[s]=0;
        vis[s] = 1;

        while (!q.isEmpty()) {
            int u = q.remove();
            for(int i=0; i<g[u].size();i++) {
                int vv = g[u].get(i);
                if(vis[vv]==0) {
                    q.add(vv);
                    d[vv] = d[u] + 6;
                    vis[vv] =1;
                }
            }
        }

        return d;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-->0) {
            v = sc.nextInt();
            e = sc.nextInt();

            ArrayList g[] = new ArrayList[v+1];
            for(int i=1; i<=v; i++) {
                g[i] = new ArrayList<Integer>();
            }

            for(int i=0; i<e; i++) {
                int a, b;
                a = sc.nextInt();
                b = sc.nextInt();
                g[a].add(b);
                g[b].add(a);
            }

            int s = sc.nextInt();
            int[] d = bfs(g, s);
            for(int i=1; i<=v; i++) {
                if(i==s) continue;
                System.out.print((d[i]==0?-1:d[i]) + " ");
            }
            System.out.println("");

        }

    }

}
