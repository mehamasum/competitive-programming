package main;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class uva610 
{
      int MAX=1005;
      int inf=(int) 1E5;

      int v, e;

      int WHITE=0;
      int GRAY=1;
      int BLACK=2;
    
      int NIL=-1;


      int color[]= new int[MAX];
      int parent[]= new int[MAX];
      int discovery[]= new int[MAX];
      int fina[]= new int[MAX];

    
      int low[]= new int[MAX];
      int ap[]= new int[MAX];
      int bridge[][]= new int[MAX][MAX];
      int graph[][]= new int[MAX][MAX];
     int printed[][]= new int[MAX][MAX];
    
      int timer=0;

      ArrayList G[] = new ArrayList[MAX];

      int child_of_root=0;
      int cnt=0;

      void init()
    {
        for(int i=0; i<MAX; i++)
            G[i]= new ArrayList();
    }
    
      void DFS_visit(int i)
    {
        //System.out.println(i);
            color[i]=GRAY;
            timer++;
            discovery[i]=timer;
            low[i]= discovery[i];

            for(int j=0;j<G[i].size();j++)
            {
                    int w=(int) G[i].get(j);

                    if(color[w] == WHITE)
                    {
                            parent[w]=i;
                            DFS_visit(w);
                            low[i] = Math.min(low[i], low[w]);

                            if (low[w] == discovery[w])
                            {
                                //System.out.println(">bridge "+i+" "+w);
                                bridge[i][w]=1;
                                bridge[w][i]=1;
                            }
                            else
                                if(bridge[w][i]==0) bridge[i][w]=1;

                    }

                    else if(parent[i] != w)
                    {
                            low[i] = Math.min(low[i], discovery[w]);
                            if(bridge[w][i]==0) bridge[i][w]=1;
                    }
            }

            color[i]=BLACK;
            timer++;
            fina[i]=timer;
    }


      void DFS()
    {
            cnt=0;
            
            for(int i=1;i<=v;i++)
                for(int j=1;j<=v;j++)
                {
                    bridge[i][j]=0;
                    printed[i][j]=0;
                }
            
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

   

    
    uva610() throws FileNotFoundException, IOException 
    {
        init();
        
        Scanner sf= new Scanner(new FileReader("610.txt"));
        //Scanner sf= new Scanner(System.in);
        int t=0;
        while(true)
        {
            t++;
            v=sf.nextInt();
            e=sf.nextInt();
            
            if(v==0 && e==0) break;
            
            for(int i=0; i<MAX; i++)
			G[i].clear();

            for(int j=0;j<e;j++)
            {
                    int a,b;
                    a=sf.nextInt();
                    b=sf.nextInt();

                    G[a].add(b);
                    G[b].add(a);
                    
            }
            
            
            DFS();

            System.out.println(t+"\n");
            for(int i=1; i<=v; i++)
            {
                    for(int j=1;j<=v;j++)
                    {
                        
                        if(bridge[i][j]==1)
                            System.out.println(i+" "+j);
                    }
            }
            System.out.println("#");
        
        }
    
    }
}
