package main;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Main 
{
    static int MAX=105;
    static int INF=(int) 1E5;

    static int v, e;

    static int cost[][] = new int [MAX][MAX];
    static int d[]= new int[MAX];

    
    static class node implements Comparable <node>
    {
        int u,d;
        node(int a,int b) {u=a; d=b;}
        
        @Override
        public int compareTo(node ob) 
        {
            //return Integer.compare(ob.d, this.d);

            return Integer.compare(ob.d, this.d);
        }
    };
    
    
    
    static void dijkstra(int s)
    {
        for(int i=0; i<d.length; i++)
                d[i]=INF;
        
        Queue q = new PriorityQueue();
        
        q.add(new node(s,0));
        d[s]=0;
        while(!q.isEmpty())
        {
            node top=(node) q.remove();
            int u=top.u;

            for(int i=1;i<=v;i++)
            {
                if(cost[u][i]!=0)
                {
                    if(d[u]+ cost[u][i] <d[i])
                    {
                        d[i]=d[u]+ cost[u][i];
                        //System.out.println("i: "+i+" d[i]:"+d[i]);
                        q.add(new node(i,d[i]));
                    }
                }
            }
        }
    }
    
    static int findMax()
    {
        int maxi=-1;
        for(int i=1;i<=v;i++)
        {
            //System.out.print(d[i]+" ");
            if(maxi<d[i])
                maxi=d[i];
        }
        //System.out.println("");
        return maxi;
    }
   

    
    public static void main(String[] args) throws FileNotFoundException, IOException 
    {
        Scanner sf= new Scanner(new FileReader("C:\\Users\\User\\Desktop\\input.txt"));
        //Scanner sf= new Scanner(System.in);
        
        while(sf.hasNextInt())
        {
            v=sf.nextInt();
            
            for(int i=2; i<=v; i++)
            {
                for(int j=1;j<i;j++)
                {
                    
                    int dis=0;
                    if(sf.hasNextInt())
                    {
                        dis=sf.nextInt();
                        //System.out.println(i+" "+j+" "+dis);
                        
                        cost[i][j]=dis;
                        cost[j][i]=dis;
                    }

                    else
                    {
                        String dummy= sf.next();
                        continue;
                    }
                }
            }
            
            dijkstra(1);
            int ans= findMax();
            System.out.println(ans);
        }
        
        System.exit(0);
    }
    
}
