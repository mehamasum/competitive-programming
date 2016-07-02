package main;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Main 
{

    static int MAX = 105;
    static int inf = (int) 1E5;

    static int v, e;

    static int WHITE = 0;
    static int GRAY = 1;
    static int BLACK = 2;

    static int NIL = -1;

    static int color[] = new int[MAX];
    static int parent[] = new int[MAX];
    static int discovery[] = new int[MAX];

    static int low[] = new int[MAX];
    static int ap[] = new int[MAX];

    static int timer = 0, cnt = 0;

    static ArrayList G[] = new ArrayList[MAX];
    static Map myMap = new HashMap();

    static void init() 
    {
        for (int i = 0; i < MAX; i++) 
        {
            G[i] = new ArrayList();
        }
    }

    static void DFS_visit(int i) 
    {

        int child = 0;

        color[i] = GRAY;
        timer++;
        discovery[i] = timer;
        low[i] = discovery[i];

        for (int j = 0; j < G[i].size(); j++) 
        {
            int w = (int) G[i].get(j);

            if (color[w] == WHITE) 
            {
                child++;
                parent[w] = i;
                DFS_visit(w);
                low[i] = Math.min(low[i], low[w]);

                if (parent[i] != NIL && discovery[i] <= low[w]) 
                {
                    if (ap[i] != 1) 
                        cnt++;
                    ap[i] = 1;
                } 
                else if (parent[i] == NIL && child > 1) 
                {
                    if (ap[i] != 1) 
                        cnt++;
                    ap[i] = 1;
                }
            } 
            else if (parent[i] != w) 
                low[i] = Math.min(low[i], discovery[w]);
        }

        color[i] = BLACK;
        timer++;
    }

    static void DFS() 
    {
        cnt = 0;
        for (int i = 0; i < v; i++) 
            ap[i] = 0;

        for (int i = 0; i < v; i++) 
        {
            color[i] = WHITE;
            parent[i] = NIL;
            low[i] = inf;
            discovery[i] = inf;
        }

        for (int i = 0; i < v; i++) 
            if (color[i] == WHITE) 
                DFS_visit(i);
    }

    public static void main(String[] args) throws FileNotFoundException, IOException 
    {
        init();

        Scanner sf = new Scanner(new FileReader("C:\\Users\\User\\Desktop\\input.txt"));
        //Scanner sf= new Scanner(System.in);

        int t = 0;

        while (true) 
        {
            t++;
            for (int i = 0; i < MAX; i++) 
                G[i].clear();

            v = sf.nextInt();

            if (v == 0) 
                break;

            String alpha[] = new String[v];
            for (int i = 0; i < v; i++) 
                alpha[i] = "";

            for (int i = 0; i < v; i++) 
            {
                String a;
                a = sf.next();
                alpha[i] = a;
            }
            Arrays.sort(alpha);

            for (int i = 0; i < v; i++) 
                myMap.put(alpha[i], i);

            e = sf.nextInt();

            for (int i = 0; i < e; i++) 
            {
                String a, b;
                a = sf.next();
                b = sf.next();

                G[(int) myMap.get(a)].add((int) myMap.get(b));
                G[(int) myMap.get(b)].add((int) myMap.get(a));
            }

            DFS();

            if(t!=1) System.out.println("");
            System.out.println("City map #" + t + ": " + cnt + " camera(s) found");
            for (int i = 0; i < v; i++) 
            {
                if (ap[i] == 1)
                    System.out.println(alpha[i]);
            }
            

            myMap.clear();

        }

        System.exit(0);
    }

}
