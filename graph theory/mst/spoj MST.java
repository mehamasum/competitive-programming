package main;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.*;

public class Main 
{
    //static final int MAX=100;
    static int par[];
    static class edge implements Comparable <edge>
    {
        int u,v,w;
        edge(int a, int b, int c)
        {
            u=a; 
            v=b;
            w=c;
        }
        
        @Override
        public int compareTo(edge ob) 
        {
            return Integer.compare(this.w, ob.w);
        }
    }
    static edge e[];
    
    static int parent(int r)
    {
        return (par[r]==r) ? r: parent(par[r]);
    }
    
    static long mst(int n)
    {
            //sort
            Arrays.sort(e);

            //initialize disjoint set
            for(int i=1; i<=n; i++)
                    par[i]=i;

            int count=0;
            long sum=0;
            for(int i=0;i<e.length;i++)
            {
                    int u= parent(e[i].u);
                    int v= parent(e[i].v);

                    if(u!=v)
                    {
                            //union
                            par[u]=v;

                            count++;
                            //System.out.println(e[i].u+" "+e[i].v+" "+e[i].w);
                            sum+=e[i].w;
                            if(count==n-1) break;

                    }
            }

            return sum;

    }

    
    public static void main(String[] args) throws FileNotFoundException 
    {
        Scanner sf= new Scanner(new FileReader("C:\\Users\\User\\Desktop\\input.txt"));
        //Scanner sf= new Scanner(System.in);
        
        int n,m;
        while(sf.hasNextInt())
        {
            n=sf.nextInt();
            m=sf.nextInt();

            par= new int[n+1];
            e=new edge[m];

            for(int i=0; i<m; i++)
            {
                    int u,v,w;
                    u=sf.nextInt();
                    v=sf.nextInt();
                    w=sf.nextInt();

                    e[i]=new edge(u,v,w);
            }

            System.out.println(mst(n));
        }
        System.exit(0);
    }
    
}
