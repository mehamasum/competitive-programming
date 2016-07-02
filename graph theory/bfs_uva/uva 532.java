package uva336;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class UVA336 
{
    static final int MAX=32;
    
    static String v[][]= new String[MAX][MAX];
    static int visited[][][]=new int[MAX][MAX][MAX];
    static int d[][][]=new int[MAX][MAX][MAX];

    static Queue ql= new LinkedList();
    static Queue qr= new LinkedList();
    static Queue qc= new LinkedList();

    static int l,r,c;

    static int dl[]={0,0,0,0,1,-1};
    static int dr[]={-1,0,0,1,0,0};
    static int dc[]={0,-1,1,0,0,0};

    static int bfs(int q, int w, int e)
    {

            ql.add(q);
            qr.add(w);
            qc.add(e);

            visited[q][w][e]=1;
            d[q][w][e]=0;


            while(!ql.isEmpty() || !qr.isEmpty() || !qc.isEmpty())
            {
                    int ul, ur, uc;

                    ul=(int) ql.remove();
                    ur=(int) qr.remove();
                    uc=(int) qc.remove();

                    for(int k=0;k<6;k++)
                    {
                            int vl,vr,vc;

                            vl=ul+dl[k];
                            vr=ur+dr[k];
                            vc=uc+dc[k];

                            if(vl>=0 && vl<l && vr>=0 && vr<r && vc>=0 && vc<c && visited[vl][vr][vc]==0 && v[vl][vr].charAt(vc)=='E')
                            {
                                    d[vl][vr][vc]=d[ul][ur][uc]+1;
                                    return d[vl][vr][vc];
                            }


                            if( (vl>=0 && vl<l) && (vr>=0 && vr<r) && (vc>=0 && vc<c) && visited[vl][vr][vc]==0 && v[vl][vr].charAt(vc)=='.')
                            {
                                    ql.add(vl);
                                    qr.add(vr);
                                    qc.add(vc);

                                    d[vl][vr][vc]=d[ul][ur][uc]+1;
                                    visited[vl][vr][vc]=1;
                            }
                    }
            }

            return -1;
    }
    

    
    public static void main(String[] args) throws FileNotFoundException, IOException 
    {
        Scanner sf= new Scanner(new FileReader("C:\\Users\\User\\Desktop\\input.txt"));
        //Scanner sf= new Scanner(System.in);
        
        while(true)
        {
            l=sf.nextInt();
            r= sf.nextInt();
            c=sf.nextInt();
            
            
            if(l==0 && r==0 && c==0) break;
            int sl=0, sr=0, sc=0;
            
            
            for(int i=0; i<MAX; i++)
                for(int j=0; j<MAX; j++)
                    v[i][j]="";
            
            for(int i=0; i<MAX; i++)
                for(int j=0;j<MAX; j++)
                    for(int k=0; k<MAX; k++)
                        visited[i][j][k]=0;
            
            for(int i=0; i<MAX; i++)
                for(int j=0;j<MAX; j++)
                    for(int k=0; k<MAX; k++)
                        d[i][j][k]=0;
            
            
            while(!ql.isEmpty()) ql.remove();
            while(!qr.isEmpty()) qr.remove();
            while(!qc.isEmpty()) qc.remove();
		
            String arr= new String();
            for(int i=0;i<l;i++)
            {
                    for(int j=0;j<r;j++)
                    {
                            v[i][j]=sf.next();
                            for(int k=0;k<c;k++)
                            {
                                    if(v[i][j].charAt(k)=='S')
                                    {
                                            sl=i; sr=j; sc=k;
                                    }
                            }

                    }
            }
            
            int ans=bfs(sl,sr,sc);
		if(ans==-1)
                    System.out.print("Trapped!\n");
		else
                    System.out.print("Escaped in "+ans+" minute(s).\n");
            
        }
        System.exit(0);
    }
    
}
