package main;
 
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.*;
 
public class Main 
{
    static final int INF=(int) 10e9;
    static int count=0;
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
    static edge e[], mst_e[];
     
    static int parent(int r)
    {
        return (par[r]==r) ? r: parent(par[r]);
    }
     
    static int mst(int n)
    {
        //sort
        Arrays.sort(e);

        //initialize disjoint set
        for(int i=1; i<=n; i++)
                par[i]=i;

        int  sum=0;
        count=0;
        for(int i=0;i<e.length;i++)
        {
            int u= parent(e[i].u);
            int v= parent(e[i].v);

            if(u!=v)
            {
                    //union
                    par[u]=v;

                    //count++;
                    //System.out.println("mst:");
                    System.out.println(e[i].u+" "+e[i].v+" "+e[i].w);
                    mst_e[count++]=new edge(e[i].u,e[i].v,e[i].w);
                    sum+=e[i].w;
                    if(count==n-1) break;

            }
        }

        return sum;
    }
    static int count2=0;
    static int mst2(int n, int a, int b, int c)
    {
        //System.out.println("hey");
        for(int i=1; i<=n; i++)
                par[i]=i;

        int  sum=0;
        count2=0;
        System.out.println("skipping:"+a+" "+b+" "+c);
        for(int i=0;i<e.length;i++)
        {
            //System.out.println("got: "+e[i].u+" "+e[i].v+" "+e[i].w);
            //System.out.println("skip: "+a+" "+b+" "+c);
            if(e[i].u==a && e[i].v==b && e[i].w==c)
                continue;
            int u= parent(e[i].u);
            int v= parent(e[i].v);

            if(u!=v)
            {
                    par[u]=v;

                    count2++;
                    sum+=e[i].w;
                    
                    System.out.println(e[i].u+" "+e[i].v+" "+e[i].w);
                    if(count2==n-1) break;
            }
        }
        if(count2!=n-1) return INF; 
        return sum;
    }
 
     
    public static void main(String[] args) throws FileNotFoundException 
    {
        Scanner sf= new Scanner(new FileReader("C:\\Users\\Student\\Desktop\\input.txt"));
        //Scanner sf= new Scanner(System.in);
         
        int n,m;
        while(sf.hasNextInt())
        {
            n=sf.nextInt();
            m=sf.nextInt();
 
            par= new int[n+1];
            e=new edge[m];
            mst_e=new edge[m];
 
            for(int i=0; i<m; i++)
            {
                    int u,v,w;
                    u=sf.nextInt();
                    v=sf.nextInt();
                    w=sf.nextInt();
 
                    e[i]=new edge(u,v,w);
            }
 
            System.out.println("best: "+mst(n));
            
            int mini=INF, result;
            for(int i=0; i<count; i++)
            {
                //System.out.println("i: "+i+" count:"+count);
                //System.out.println("skipped >>:"+mst_e[i].u+" "+mst_e[i].v+" "+mst_e[i].w);
                result=mst2(n,mst_e[i].u,mst_e[i].v,mst_e[i].w);
                //System.out.println("skipped <<:"+mst_e[i].u+" "+mst_e[i].v+" "+mst_e[i].w);
                mini=Math.min(mini,result);
            }
            
            System.out.println("second best: "+mini);
        }
        System.exit(0);
    }
     
}