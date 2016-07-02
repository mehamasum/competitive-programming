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
        int a,n;
        n=sc.nextInt(); a=sc.nextInt();
        BigInteger N= new BigInteger(Integer.toString(n));
        BigInteger A= new BigInteger(Integer.toString(a));
        //System.out.println(N+" "+A);
        BigInteger SUM= BigInteger.ZERO, I;
        for(int i=1; i<=n; i++)
        {
            I=new BigInteger(Integer.toString(i));
            //System.out.println(SUM+" "+I.multiply(A.pow(i))+" "+A.pow(i));
            SUM=SUM.add(I.multiply(A.pow(i)));
        }
        
        System.out.println(SUM);
        
    }
  } 
}