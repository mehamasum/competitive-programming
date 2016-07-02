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

    static int child_of_root=0;
    static int cnt=0;

    static void init()
    {
        for(int i=0; i<MAX; i++)
            G[i]= new ArrayList();
    }
    
    static void DFS_visit(int i)
    {
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
                                    if(i<w)
                                            bridge[i][w]=1;
                                    else
                                            bridge[w][i]=1;

                                            cnt++;
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
            cnt=0;
            
            for(int i=0;i<v;i++)
                for(int j=0;j<v;j++)
                    bridge[i][j]=0;
            
            for(int i=0;i<v;i++)
            {
                    color[i] = WHITE;
                    parent[i]=NIL;
                    low[i]=inf;
                    fina[i]=inf; 
                    discovery[i]=inf;
            }

            for(int i=0;i<v;i++)
                    if(color[i]==WHITE)
                            DFS_visit(i);
    }

   

    
    public static void main(String[] args) throws FileNotFoundException, IOException 
    {
        init();
        
        Scanner sf= new Scanner(new FileReader("C:\\Users\\User\\Desktop\\input.txt"));
        //Scanner sf= new Scanner(System.in);
        
        while(sf.hasNextInt())
        {
            v=sf.nextInt();
            for(int i=0; i<MAX; i++)
			G[i].clear();

            if(v==0)
            {
                    System.out.println("0 critical links");
                    System.out.println("");
                    continue;
            }
            
            for(int i=0; i<v; i++)
            {
                    int a, e;
                    String dummyS="";
                    char dummyC[]= new char[100];
                    
                    a=sf.nextInt();
                    dummyC=sf.next().toCharArray();
                    dummyS= new String(dummyC, 1, dummyC.length-2);
                    
                    e=Integer.parseInt(dummyS);

                    for(int j=0;j<e;j++)
                    {
                            int b;
                            b=sf.nextInt();

                            G[a].add(b);
                    }
            }
            
            DFS();

            System.out.println(cnt+" critical links");


            for(int i=0; i<v; i++)
                    for(int j=0;j<v;j++)
                        if(bridge[i][j]==1)
                            System.out.println(i+" - "+j);
            System.out.println("");
            
           
        }
        
        System.exit(0);
    }
    
}
