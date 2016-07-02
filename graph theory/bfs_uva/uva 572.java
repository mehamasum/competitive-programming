package uva336;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class UVA336 
{
    static final int MAX=105;
    
    static String v[]= new String[MAX];
    static int visited[][]=new int[MAX][MAX];
    static Queue qr= new LinkedList();
    static Queue qc= new LinkedList();

    static int cnt=0;
    static int r,c;


    static int dr[]={-1,-1,-1,0,0,1,1,1};
    static int dc[]={-1,0,1,-1,1,-1,0,1};

    static void bfs_visit(int i, int j)
    {
            qr.add(i);
            qc.add(j);

            while(!qr.isEmpty() || !qc.isEmpty())
            {
                    int ur,uc;
                    ur=(int) qr.remove();
                    uc=(int) qc.remove();
                    
                    for(int k=0;k<8;k++)
                    {
                            int vr,vc;
                            vr=ur+dr[k];
                            vc=uc+dc[k];
                            if(vr>=0 && vr<r && vc>=0 && vc<c && visited[vr][vc]==0 && v[vr].charAt(vc)=='@')
                            {
                                    qr.add(vr);
                                    qc.add(vc);
                                    visited[vr][vc]=1;
                            }
                    }
            }
    }

    static int bfs()
    {
            for(int i=0;i<r;i++)
                    {
                            for(int j=0;j<c;j++)
                            {
                                    if(v[i].charAt(j)=='@' && visited[i][j]==0)
                                    {
                                            visited[i][j]=1;
                                            bfs_visit(i,j);
                                            cnt++;
                                    }
                            }
                    }
            return cnt;
    }
    

    
    public static void main(String[] args) throws FileNotFoundException, IOException 
    {
        //Scanner sf= new Scanner(new FileReader("C:\\Users\\User\\Desktop\\input.txt"));
        Scanner sf= new Scanner(System.in);
        
        while(true)
        {
            r= sf.nextInt();
            c=sf.nextInt();
            
            if(r==0) break;
            cnt=0;
            
            
            for(int i=0; i<MAX; i++)
                    v[i]="";
            
            for(int i=0; i<MAX; i++)
                for(int j=0;j<MAX; j++)
                    visited[i][j]=0;
            
            for(int i=0;i<r;i++)
            {
                v[i]=sf.next();
            }
            
            System.out.println(bfs());
            
            
        }
        System.exit(0);
    }
    
}
