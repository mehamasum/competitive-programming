package scc;
 
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.*;
 
public class SCC 
{
    static final int MAX=1000005;
    static int par[]=new int[MAX];
    static edge e[]=new edge[MAX];
    
    
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
 
            int count=0, sum=0;
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
        Scanner sf= new Scanner(new FileReader("C:\\Users\\Student\\Desktop\\input.txt"));
        //Scanner sf= new Scanner(System.in);
         
        int n,m,k,caseNo=1;
        while(sf.hasNextInt())
        {
            int prevSum=0;
            n=sf.nextInt();
            //System.out.println(n);

            for(int i=0; i<n-1; i++)
            {
                int u,v,w;
                u=sf.nextInt();
                v=sf.nextInt();
                w=sf.nextInt();
                //System.out.println(u+" "+v+" "+w);
                prevSum+=w;
            }
            
            k=sf.nextInt();
            //System.out.println(k);
            for(int i=0; i<k; i++)
            {
                    int u,v,w;
                    u=sf.nextInt();
                    v=sf.nextInt();
                    w=sf.nextInt();
                    
                    //System.out.println(u+" "+v+" "+w);
                    e[i]=new edge(u,v,w);
            }
            
            m=sf.nextInt();
            //System.out.println(k);
            for(int i=k; i<m+k; i++)
            {
                    int u,v,w;
                    u=sf.nextInt();
                    v=sf.nextInt();
                    w=sf.nextInt();
 
                    e[i]=new edge(u,v,w);
            }
            
            for(int i=m+k; i<MAX; i++)
            {
                e[i]=new edge(0,0,100000000);
            }
            if(caseNo!=1)
                System.out.println("");
            System.out.println(prevSum);
            System.out.println(mst(n));
            
            caseNo++;
            
        }
        System.exit(0);
    }
     
}