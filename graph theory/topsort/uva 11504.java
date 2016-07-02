package uva336;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class UVA336 
{
    static int MAX=100005;

    static int WHITE=0;
    static int GRAY=1;
    static int BLACK=2;

    static int v,e;
    
    static int color[]= new int[MAX];
    static Stack st= new Stack();
    
    static int timer=0;

    static Map myMap= new HashMap();
    
    static ArrayList G[]= new ArrayList[MAX];
    static ArrayList GG[]= new ArrayList[MAX];


    static void init()
    {
        for(int i=0; i<MAX; i++)
        {
            G[i]= new ArrayList();
            GG[i]= new ArrayList();
        }
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
            st.push(i);
            timer++;
    }

    static void DFS()
    {
            timer=0;
            for(int i=1;i<=v;i++)
            {
                    if(color[i]==WHITE)
                            DFS_visit(i);
            }
    }

    static int DFS2()
    {
        
            int cnt=0;
            timer=0;
            while(!st.isEmpty())
            {
                    int j=(int) st.pop();
                    //System.out.println("popped: "+j+" color: "+color[j]);

                    if(color[j]==WHITE)
                    {
                        //System.out.println("j"+j);
                            DFS_visit(j);
                            cnt++;
                    }
            }
            return cnt;
    }   

    
    public static void main(String[] args) throws FileNotFoundException, IOException 
    {
        init();
        
        Scanner sf= new Scanner(new FileReader("C:\\Users\\User\\Desktop\\input.txt"));
        //Scanner sf= new Scanner(System.in);
        
        int T;
        T=sf.nextInt();
        
        for(int t=0;t<T;t++)
        {
            v= sf.nextInt();
            e=sf.nextInt();
            
            
            for(int i=0;i<MAX;i++)
            {
                G[i].clear();
                GG[i].clear();
            }
            for(int i=0; i<color.length; i++)
                color[i]=0;
            
            int a,b;
            for(int i=0;i<e;i++)
            {
                    a=sf.nextInt();
                    b=sf.nextInt();

                    G[a].add(b);
            }
            
            DFS();
            for(int i=0; i<color.length; i++)
                color[i]=0;
            int ans=DFS2();
            System.out.println(ans);

        }
        System.exit(0);
    }
    
}
