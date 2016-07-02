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
        String s;
        s=sc.nextLine();
        BigInteger N=new BigInteger(s);
        if(N.equals(BigInteger.ZERO)) break;
        
        int len=s.length();
        char arr[]=s.toCharArray();
        int l=arr[len-1]-48;
        
        BigInteger L=new BigInteger(Integer.toString(l));
        BigInteger MUL=L.multiply(BigInteger.valueOf(5));
        String a=new String(arr, 0, len-1);
        BigInteger A=new BigInteger(a);
        
        BigInteger SUB;
        SUB=A.subtract(MUL).abs();
        
        //System.out.println(N+" "+A);
        
        if(SUB.mod(BigInteger.valueOf(17)).equals(BigInteger.ZERO))
            System.out.println("1");
        else 
            System.out.println("0");
        
    }
  } 
}