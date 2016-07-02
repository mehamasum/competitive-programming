package main;

import java.util.Scanner;
import java.math.BigInteger;

class Main 
{ 
  public static void main(String[] args) 
  {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    while (N-- > 0) 
    { 
      BigInteger p = sc.nextBigInteger();
      String ch = sc.next(); 
      BigInteger q = sc.nextBigInteger();
      BigInteger gcd_pq = p.gcd(q);
      System.out.println(p.divide(gcd_pq) + " / " + q.divide(gcd_pq));
    }
    System.exit(0);
  }
}
