package main;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.*;

public class Main 
{
    static int MAX=10005;

    static int WHITE=0;
    static int GRAY=1;
    static int BLACK=2;

    static int v,e,l,cnt=0;
    static int color[]= new int[MAX];
    static int timer=0;

    static ArrayList G[] = new ArrayList[MAX];
    
    static void init()
    {
        for(int i=0; i<MAX; i++)
            G[i]= new ArrayList();
    }
    
    static void DFS_visit(int i)
    {
        cnt++;
        color[i]=GRAY;
        timer++;
        for(int j=0;j<G[i].size();j++)
        {
                int u=(int) G[i].get(j);
                if(color[u]==WHITE)
                    DFS_visit(u);
        }
        color[i]=BLACK;
    }
    
    public static void main(String[] args) throws FileNotFoundException 
    {
        init();
        Scanner sf= new Scanner(new FileReader("C:\\Users\\User\\Desktop\\input.txt"));
        //Scanner sf= new Scanner(System.in);
        
        while(sf.hasNext())
        {
            int T=sf.nextInt();
            for(int t=1;t<=T;t++)
            {
                v= sf.nextInt();
                e=sf.nextInt();
                l=sf.nextInt();
                //System.out.println(v+" "+e+" "+l);
                //arr.clear();
                for(int i=0;i<MAX;i++)
                        G[i].clear();
                for(int i=0; i<MAX; i++)
                    color[i]=0;

                for(int i=0; i<e;i++)
                {
                        int a,b;
                        a= sf.nextInt();
                        b=sf.nextInt();
                        //System.out.println(a+" "+b);
                        G[a].add(b);
                }
                int ans=0;
                for(int i=0; i<l;i++)
                {
                        int a;
                        a= sf.nextInt();
                        //System.out.println(a);
                        cnt=0;
                        if(color[a]==WHITE)
                        {
                            timer=0;
                            DFS_visit(a);
                            //System.out.println(">"+cnt);
                            ans+=cnt;
                        }
                }
                System.out.println(ans);
            }
        }
        System.exit(0);
    }
    
}
