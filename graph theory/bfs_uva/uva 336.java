package uva336;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.*;

public class UVA336 
{
    static int n, m;
    static ArrayList G[]= new ArrayList[100];
    static Map mymap = new HashMap();

    static void init()
    {
        for(int i=0; i<100; i++)
            G[i]= new ArrayList();
    }
    
    

    
    static int bfs(int src, int lev) 
    {
        int cnt = 0;
        int visited[] = new int[100];
        int level[] = new int[100];
        int parent[] = new int[100];

        Queue Q = new LinkedList();
        Q.add(src);

        visited[src] = 1;
        level[src] = 0;
        while (!Q.isEmpty()) 
        {
            int u = (int) Q.element();
            if (level[u] <= lev - 1) 
            {
                for (int i = 0; i < G[u].size(); i++) 
                {
                    int v = (int) G[u].get(i);
                    if (visited[v] == 0) 
                    {
                        cnt++;
                        level[v] = level[u] + 1;
                        parent[v] = u;
                        visited[v] = 1;
                        Q.add(v);
                    }
                }
                Q.remove();
            } 
            else 
            {
                break;
            }
        }
        return n - cnt - 2;
    }

    
    
    public static void main(String[] args) throws FileNotFoundException 
    {
        init();
        int caseNo=1;
        //Scanner sf= new Scanner(new FileReader("C:\\Users\\User\\Desktop\\input.txt"));
        Scanner sf= new Scanner(System.in);
        while(true)
        {
            m= sf.nextInt();
            if(m==0) break;
            
            n = 1;
            
            for (int i = 0; i < m; i++) 
            {
                int a, b;
                a=sf.nextInt();
                b=sf.nextInt();

                if (!mymap.containsKey(a))
                    mymap.put(a, n++);
                if (!mymap.containsKey(b))
                    mymap.put(b, n++);

                G[ (int) mymap.get(a)].add( (int) mymap.get(b) );
                G[ (int) mymap.get(b)].add( (int) mymap.get(a) );
            }
                
                
            int s, d;
            while(true)
            {
                s=sf.nextInt();
                d=sf.nextInt();
                if(s==0 && d==0) break;
                int ans=bfs((int) mymap.get(s),d);
                System.out.print( "Case " + caseNo + ": " + ans + " nodes not reachable from node " +s+ " with TTL = " +d+ ".\n" );
                caseNo++;

            }

            mymap.clear();
            for(int j=0; j<100;j++)
                G[j].clear();
            
        }
        System.exit(0);
    }
    
}
