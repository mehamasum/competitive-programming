package main;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Main 
{
    static int MAX=1000005;
    static int INF=(int) 1E11;

    static int v, e;
    
    static ArrayList G[]= new ArrayList[MAX];
    static ArrayList GR[]= new ArrayList[MAX];

    static ArrayList cost[] = new ArrayList[MAX];
    static ArrayList costR[] = new ArrayList [MAX];

    static int d[]= new int[MAX];    
    static int dR[]= new int[MAX];


    static void init()
    {
        for(int i=0; i<MAX; i++)
        {
            G[i]= new ArrayList();
            GR[i]= new ArrayList();
            cost[i]= new ArrayList();
            costR[i]= new ArrayList();
            
        }
    }
    
    static void clear()
    {
        for(int i=1; i<=v; i++)
        {
            G[i].clear();
            GR[i].clear();
            cost[i].clear();
            costR[i].clear();
        }
    }
    
    static class node implements Comparable <node>
    {
        int u,d;
        node(int a,int b) {u=a; d=b;}
        
        @Override
        public int compareTo(node ob) 
        {
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

            for(int i=0;i<G[u].size();i++)
            {
                int j=(int) G[u].get(i);
                //System.out.println(u+" "+G[u].get(i)+" "+cost[u].get(i));
                
                    if(d[u]+ (int)cost[u].get(i) <d[j])
                    {
                        d[j]=d[u]+ (int)cost[u].get(i);
                        q.add(new node(j,d[j]));
                    }
            }
        }
    }
    
    static void dijkstraR(int s)
    {
        for(int i=0; i<dR.length; i++)
                dR[i]=INF;
        
        Queue q = new PriorityQueue();
        
        q.add(new node(s,0));
        dR[s]=0;
        while(!q.isEmpty())
        {
            node top=(node) q.remove();
            int u=top.u;

            for(int i=0;i<GR[u].size();i++)
            {
                int j=(int) GR[u].get(i);

                //System.out.println(">"+u+" "+GR[u].get(i)+" "+costR[u].get(i));

                    if(dR[u]+ (int)costR[u].get(i) <dR[j])
                    {
                        //System.out.println(">"+dR[j]);
                        dR[j]=dR[u]+ (int)costR[u].get(i);
                        q.add(new node(j,dR[j]));
                        //System.out.println(">>"+dR[j]);

                    }
            }
        }
    }
    
    static int findTotal()
    {
        int sum=0;
        for(int i=1;i<=v;i++)
        {
            //System.out.println("..."+d[i]+" "+dR[i]);
            sum+=d[i]+dR[i];
        }
        return sum;
    }

    
    public static void main(String[] args) throws FileNotFoundException, IOException 
    {
        Scanner sf= new Scanner(new FileReader("C:\\Users\\User\\Desktop\\input.txt"));
        //Scanner sf= new Scanner(System.in);
        
        init();
        
        while(sf.hasNextInt())
        {
            int T=sf.nextInt();
            
            for(int t=1;t<=T;t++)
            {
                v=sf.nextInt();
                e=sf.nextInt();

                for(int j=1;j<=e;j++)
                {
                    int a,b,c=0;
                    a=sf.nextInt();
                    b=sf.nextInt();
                    c=sf.nextInt();

                    G[a].add(b);
                    cost[a].add(c);
                    
                    GR[b].add(a);
                    costR[b].add(c);
                    
                    
                    //System.out.println(a+" "+b+" "+dis);
                    //cost[a][b]=dis;
                    //costR[b][a]=dis;
                }

                dijkstra(1);
                dijkstraR(1);

                int ans= findTotal();
                System.out.println(ans);
                
                clear();
            }
        }
        
        System.exit(0);
    }
    
}
