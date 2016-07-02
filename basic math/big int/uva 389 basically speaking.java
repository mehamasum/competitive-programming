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
        String a;
        a=sc.next(); 
        BigInteger C,D;
        int from=sc.nextInt();
        int to=sc.nextInt();
        
        C= new BigInteger(a, from);
        String ans=C.toString(to).toUpperCase();
        int len=ans.length();
        if(len>7)
            ans="ERROR";
        
        System.out.println(String.format("%7s",ans));
        
    }
  } 
}