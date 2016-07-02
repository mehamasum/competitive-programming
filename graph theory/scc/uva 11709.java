package uva336;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class UVA336 
{
    static int MAX=1005;

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

    static void DFS_visit2(int i)
    {

            color[i]=GRAY;
            //System.out.println("node: "+i+" color changed to: "+color[i]);

            timer++;
            for(int j=0;j<GG[i].size();j++)
            {
                    int u=(int) GG[i].get(j);
                    if(color[u]==WHITE)
                            DFS_visit2(u);
            }
            color[i]=BLACK;
            //System.out.println("node: "+i+" color changed to: "+color[i]);

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
                            DFS_visit2(j);
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
        
        while(true)
        {
            v= sf.nextInt();
            e=sf.nextInt();
            
            if(v==0 && e==0) break;
            
            for(int i=0;i<MAX;i++)
            {
                G[i].clear();
                GG[i].clear();
            }
            for(int i=0; i<color.length; i++)
                color[i]=0;
            myMap.clear();
            
            String a, b;
            a=sf.nextLine(); //dummy
            for(int i=1;i<=v;i++)
            {
                    a=sf.nextLine();
                    //System.out.println(">"+a);
                    myMap.put(a, i);
            }
            
            //System.out.println(myMap);
            
            //a=sf.nextLine(); //dummy
            for(int i=0;i<e;i++)
            {
                    a=sf.nextLine();
                    //System.out.println(a);
                    b=sf.nextLine();
                    //System.out.println(b);

                    G[ (int)myMap.get(a) ].add ( (int)myMap.get(b) );
                    GG[ (int)myMap.get(b) ].add ( (int)myMap.get(a) );

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
