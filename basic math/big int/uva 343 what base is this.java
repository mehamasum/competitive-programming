package main;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;
import java.math.BigInteger;

class Main 
{
  public static void main(String[] args) throws FileNotFoundException 
  {
    Scanner sc= new Scanner(new FileReader("C:\\Users\\User\\Desktop\\input.txt"));
    //Scanner sc = new Scanner(System.in);
    while(sc.hasNext())
    {
        String a,b;
        a=sc.next(); b=sc.next();    
        BigInteger C,D;
        boolean flag=false;
        int i=0,j=0;
        for(i=2; i<=36; i++)
        {
            try
            {
                C= new BigInteger(a, i);
            }
            catch(Exception e)
            {
                continue;
            }
            
            for(j=2;j<=36;j++)
            {
                
                try
                {
                    D= new BigInteger(b, j);
                }
                catch(Exception e)
                {
                    continue;
                }
                //System.out.println(C+"in"+i+" "+D+"in"+j);
                if(C.subtract(D).equals(BigInteger.ZERO))
                {
                    flag=true;
                    break;
                }
                
            }
            if(flag) break;
        }
        
        if(flag)
            System.out.println(a+" (base "+i+") = "+b+" (base "+j+")");
        else
            System.out.println(a+" is not equal to "+b+" in any base 2..36");
        
        
    }
  } 
}