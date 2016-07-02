package main;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Main 
{
    static int MAX=105;
    static int inf=(int) 1E5;

    static int v, e;

    static int WHITE=0;
    static int GRAY=1;
    static int BLACK=2;
    
    static int NIL=-1;


    static int color[]= new int[MAX];
    static int parent[]= new int[MAX];
    static int discovery[]= new int[MAX];
    static int fina[]= new int[MAX];

    
    static int low[]= new int[MAX];
    static int ap[]= new int[MAX];
    static int bridge[][]= new int[MAX][MAX];

    
    static int timer=0;

    static ArrayList G[] = new ArrayList[MAX];

    static void init()
    {
        for(int i=0; i<MAX; i++)
            G[i]= new ArrayList();
    }
    
    static void DFS_visit(int i)
    {
        
        int child=0;
        
            color[i]=GRAY;
            timer++;
            discovery[i]=timer;
            low[i]= discovery[i];

            for(int j=0;j<G[i].size();j++)
            {
                    int w=(int) G[i].get(j);

                    if(color[w] == WHITE)
                    {
                        child++;
                            parent[w]=i;
                            DFS_visit(w);
                            low[i] = Math.min(low[i], low[w]);

                            if (low[w] == discovery[w])
                            {
                                    if(i<w)
                                            bridge[i][w]=1;
                                    else
                                            bridge[w][i]=1;
                            }
                            
                            if ( parent[i]!=NIL && discovery[i]<=low[w])
                            {
				ap[i]=1;
                                //System.out.println("ap"+i);
                            }
                            
                            else if(parent[i]==NIL && child>1)
                            {
				ap[i]=1;
                                //System.out.println("ap"+i);
                            }
                    }

                    else if(parent[i] != w)
                            low[i] = Math.min(low[i], discovery[w]);
            }

            color[i]=BLACK;
            timer++;
            fina[i]=timer;
    }


    static void DFS()
    {
            for(int i=1;i<=v;i++)
                ap[i]=0;
            
            for(int i=1;i<=v;i++)
                for(int j=1;j<=v;j++)
                    bridge[i][j]=0;
            
            for(int i=1;i<=v;i++)
            {
                    color[i] = WHITE;
                    parent[i]=NIL;
                    low[i]=inf;
                    fina[i]=inf; 
                    discovery[i]=inf;
            }

            for(int i=1;i<=v;i++)
                    if(color[i]==WHITE)
                            DFS_visit(i);
    
    }

   

    
    public static void main(String[] args) throws FileNotFoundException, IOException 
    {
        init();
        
        Scanner sf= new Scanner(new FileReader("C:\\Users\\User\\Desktop\\input.txt"));
        //Scanner sf= new Scanner(System.in);
        Scanner sc;
        while(true)
        {
            for(int i=0; i<MAX; i++)
                G[i].clear();
            
            String first="";
            first=sf.nextLine();
            //System.out.println(first);
            
            sc=new Scanner(first);
            v=sc.nextInt();
            
            //System.out.println("V:"+v);
            if(v==0)
                break;
            
            int i;
            for(i=1; i<=v; i++)
            {
                int a;
                
                String line= sf.nextLine();
                //System.out.println(line);
                sc= new Scanner(line);
                
                a=sc.nextInt();
                if(a==0) break;
                //System.out.println("a:"+a);

                while(sc.hasNextInt())
                {
                    int b=sc.nextInt();
                    //System.out.println("b:"+b);

                    G[a].add(b);
                    G[b].add(a);
                }
                
                
            }
            if(i==v+1)
            {
                //System.out.println("here");
                
                first=sf.nextLine();
            
                sc=new Scanner(first);
                int dummy=sc.nextInt();
            }
                
            
            DFS();


            int ans=0;
            for(int k=1; k<=v; k++)
                if(ap[k]==1)
                    ans++;
            System.out.println(ans);
            
           
        }
        
        System.exit(0);
    }
    
}
