package main;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Main 
{
    static int MAXN = 105;
    static int MAXE = 1005;

    static int INF = (int) 1E5;

    static int v, e;

    static int d[] = new int[MAXN];
    static int cost[][] = new int[MAXN][MAXN];

    static Map myMap = new HashMap();

    static void bellman(int s, int y) 
    {
        for (int i = 1; i <= v; i++) 
            d[i] = INF;
        d[s] = 0;

        for (int m = 1; m <= y; m++) 
        {
            for (int i = v; i >= 1; i--) 
            {
                for (int j = v; j >= 1; j--) 
                {
                    if (cost[i][j] >= 0) 
                    {
                        if (d[i] + cost[i][j] <= d[j])
                            d[j] = d[i] + cost[i][j];
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws FileNotFoundException, IOException 
    {
        Scanner sf = new Scanner(new FileReader("C:\\Users\\User\\Desktop\\input.txt"));
        //Scanner sf= new Scanner(System.in);

        int T = 0;

        while (sf.hasNextInt()) 
        {
            T = sf.nextInt();
            for (int t = 1; t <= T; t++) 
            {
                myMap.clear();

                v = sf.nextInt();
                
                for (int i = 1; i <= v; i++)
                    for (int j = 1; j <= v; j++)
                        cost[i][j] = -1;
                
                for (int i = 1; i <= v; i++) 
                {
                    String a = "";
                    a = sf.next();
                    myMap.put(a, i);
                    //System.out.println(a+" "+i);
                }

                e = sf.nextInt();
                
               
                
                for (int i = e; i >= 1; i--) 
                {
                    String a, b;
                    int c;
                    a = sf.next();
                    b = sf.next();
                    c = sf.nextInt();
                    
                    

                    int p = (int) myMap.get(a);
                    int q = (int) myMap.get(b);
                    //System.out.println(p+" "+q+" "+c+" "+cost[p][q]);

                    
                    if (cost[p][q] >= 0) 
                    {
                        if (c < cost[p][q])
                            cost[p][q] = c;
                    } 
                    else 
                        cost[p][q] = c;
                    
                    //System.out.println(p+" "+q+" "+cost[p][q]);
                }

                int q;
                q = sf.nextInt();
                if (t != 1) 
                    System.out.println("");
                System.out.println("Scenario #" + t);
                for (int i = 1; i <= q; i++) 
                {
                    int x;
                    x = sf.nextInt();

                    if (x == 0) 
                    {
                        if (cost[1][v] >= 0) 
                            System.out.println("Total cost of flight(s) is $" + cost[1][v]);
                         else 
                            System.out.println("No satisfactory flights");
                        
                    } 
                    else 
                    {
                        bellman(1, x + 1);
                        //path(v);
                        if (d[v] == INF)
                            System.out.println("No satisfactory flights");
                        else
                            System.out.println("Total cost of flight(s) is $" + d[v]);
                    }
                }

            }

            System.exit(0);
        }
    }

}
