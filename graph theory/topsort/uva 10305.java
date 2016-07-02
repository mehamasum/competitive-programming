package uva336;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.*;

public class UVA336 
{
    static int MAX=105;

    static int WHITE=0;
    static int GRAY=1;
    static int BLACK=2;

    static int v,e;
    static int color[]= new int[MAX];
    static int timer=0;

    static ArrayList G[] = new ArrayList[MAX];
    static ArrayList arr= new ArrayList();

    
    static void init()
    {
        for(int i=0; i<MAX; i++)
            G[i]= new ArrayList();
    }
    
    static void DFS_visit(int i)
    {
        color[i]=GRAY;
        timer++;
        for(int j=0;j<G[i].size();j++)
        {
                int u=(int) G[i].get(j);
                if(color[u]==WHITE)
                        DFS_visit(u);
        }
        color[i]=BLACK;
        arr.add(i);
    }
    static void DFS()
    {
        for(int i=1;i<=v;i++)
                if(color[i]==WHITE)
                        DFS_visit(i);
    }
    
    public static void main(String[] args) throws FileNotFoundException 
    {
        init();
        Scanner sf= new Scanner(new FileReader("C:\\Users\\User\\Desktop\\input.txt"));
        //Scanner sf= new Scanner(System.in);
        
        while(true)
        {
            v= sf.nextInt();
            e=sf.nextInt();
            
            if(v==0 && e==0) break;

            arr.clear();
            for(int i=0;i<v;i++)
                    G[i].clear();
            for(int i=0; i<color.length; i++)
                color[i]=0;

            for(int i=0; i<e;i++)
            {
                    int a,b;
                    a= sf.nextInt();
                    b=sf.nextInt();
                    G[a].add(b);
            }
                
            DFS();
            
            Collections.reverse(arr);
            
            for(int i=0;i<v;i++)
                System.out.print(arr.get(i)+" ");
            System.out.println("");
            
        }
        System.exit(0);
    }
    
}
