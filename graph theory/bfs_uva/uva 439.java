package main;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Main 
{
    static final int MAX=70;
    
    static int visited[][]=new int[MAX][MAX];
    static int move[][]=new int[MAX][MAX];
    static Queue qr= new LinkedList();
    static Queue qc= new LinkedList();

    static int r=8,c=8;


    static int dr[]={+1,+2,+2,+1,-1,-2,-2,-1};
    static int dc[]={+2,+1,-1,-2,+2,+1,-1,-2};

    static int bfs(int i, int j, int x, int y)
    {
        move[i][j]=0;
        visited[i][j]=1;
        qr.add(i);
        qc.add(j);

        while(!qr.isEmpty() || !qc.isEmpty())
        {
            int ur,uc;
            ur=(int) qr.remove();
            uc=(int) qc.remove();
            
            //System.out.println(ur+" "+uc);

            for(int k=0;k<8;k++)
            {
                int vr,vc;
                vr=ur+dr[k];
                vc=uc+dc[k];
                //System.out.println("> "+vr+" "+vc);
                if(vr>=0 && vr<r && vc>=0 && vc<c && visited[vr][vc]==0)
                {
                    visited[vr][vc]=1;
                    move[vr][vc]=move[ur][uc]+1;
                    if(vr==x && vc==y) return move[vr][vc];
                    qr.add(vr);
                    qc.add(vc);
                    visited[vr][vc]=1;
                }
            }
        }
        return 0;
    }

    

    
    public static void main(String[] args) throws FileNotFoundException, IOException 
    {
        Scanner sf= new Scanner(new FileReader("C:\\Users\\User\\Desktop\\input.txt"));
        //Scanner sf= new Scanner(System.in);
        
        while(sf.hasNext())
        {
            String a,b;
            a=sf.next();
            b=sf.next();
            
            int x1,y1, x2, y2;
            x1=a.charAt(0)%97;
            y1=a.charAt(1)%49;
            
            x2=b.charAt(0)%97;
            y2=b.charAt(1)%49;
            
            //System.out.println(x1+" "+y1+" "+x2+" "+y2);
            System.out.print("To get from "+a+" to "+b+" takes ");
            if(x1==x2 && y1==y2) System.out.print("0");
            else System.out.print(bfs(x1, y1, x2, y2));
            System.out.println(" knight moves.");
            
            for(int i=0; i<MAX; i++)
                for(int j=0;j<MAX; j++)
                    visited[i][j]=0;
            for(int i=0; i<MAX; i++)
                for(int j=0;j<MAX; j++)
                    move[i][j]=0;
            qc.clear();
            qr.clear();
            
        }
        System.exit(0);
    }
    
}
