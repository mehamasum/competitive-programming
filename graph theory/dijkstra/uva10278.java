package main;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class uva10278 
{
    int MAX=505;
    int INF=(int) 1E5;

    int v, e, f;

    int cost[][] = new int [MAX][MAX];
    int d[]= new int[MAX];
    int fire[]=new int [MAX];

    
    class node implements Comparable <node>
    {
        int u,d;
        node(int a,int b) {u=a; d=b;}
        
        @Override
        public int compareTo(node ob) 
        {
            //return Integer.compare(ob.d, this.d);

            return Integer.compare(ob.d, this.d);
        }
    }
    
    void clear()
    {
        for(int i=1; i<=v;i++)
        {
            fire[i]=0;
            for(int j=1;j<=v;j++)
                cost[i][j]=0;
        }
        
    }
    
    void dijkstra(int s)
    {
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
    
    void khichuri(int s)
    {
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
   
    int findMax()
    {
        int maxi=-1;
        for(int i=1; i<=v; i++)
            maxi=Math.max(maxi,d[i]);
        return maxi;
            
    }

    
    uva10278() throws FileNotFoundException, IOException 
    {
        Scanner sf= new Scanner(new FileReader("10278.txt"));
        //Scanner sf= new Scanner(System.in);
        
        int T=sf.nextInt();
        //System.out.println(T);
        for(int t=1;t<=T;t++)
        {
            for(int i=0; i<d.length; i++)
                d[i]=INF;
            
            f=sf.nextInt();
            v=sf.nextInt();
            
            //System.out.println(f+" "+v);
            
            for(int i=1; i<=f;i++)
            {
                int n=sf.nextInt();
                fire[n]=1;
                //System.out.println(fire[i]);
            }
            
            String line=sf.nextLine();
            while(sf.hasNextLine())
            {
                line=sf.nextLine();
                //System.out.println(">>"+line);
                if(line.length()==0)
                    break;
                Scanner sl= new Scanner(line);
                int a, b, c;
                a=sl.nextInt(); b=sl.nextInt(); c=sl.nextInt();
                //System.out.println(a+" "+b+" "+c);
                cost[a][b]=c;
                cost[b][a]=c;
            }
            
            
            for(int i=1; i<=v; i++)
            {
                //System.out.println("it:"+i);
                if(fire[i]==1)
                {
                    khichuri(i);
                }
            }
            
            int clone[];
            clone=d.clone();
          
            
            int maxi=(int)1e10, ans=0,i=1;
            for(i=1; i<=v; i++)
            {
                //if(fire[i]!=1)
                {
                    dijkstra(i);
                    if(maxi>findMax())
                    {
                        maxi=findMax();
                        ans=i;
                    }
                    d=clone.clone();
                }
            }
            
            
            if(t!=1) System.out.println("");
            System.out.println(ans);
            clear();
        }
        
        //System.exit(0);
    }
    
}
