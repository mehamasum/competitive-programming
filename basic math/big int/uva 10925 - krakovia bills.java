package main;

import java.util.Scanner;
import java.math.BigInteger;

class Main 
{
  public static void main(String[] args) 
  {
    Scanner sc = new Scanner(System.in);
    int caseNo = 1;
    while (true) 
    {
      BigInteger N = sc.nextBigInteger(), F = sc.nextBigInteger();
      if (N.intValue() == 0 && F.intValue() == 0) break;
      BigInteger sum = BigInteger.ZERO;
      for (int i = 0; i < N.intValue(); i++) 
      {
        BigInteger V = sc.nextBigInteger(); 
        sum = sum.add(V);
      }
      System.out.println("Bill #" + (caseNo++) + " costs " +
        sum + ": each friend should pay " + sum.divide(F));
      System.out.println();
    } 
  } 
}        
