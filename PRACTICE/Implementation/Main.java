/**
 ** Java Program to implement Pollard Rho Algorithm
 **/
 import java.io.*;
  import java.util.*;
import java.util.Scanner;
 
/** Class  Main **/
public class Main    {
	
    public static int __num=0;
    public static Long [] Store=new Long[1000000];
    private static final long C = 1; 
    /** function X * X + C, change value of C as required **/
    private long f(long X)    
    {
        return X * X + C;
    }
    /** get divisor **/
    private long rho(long N) 
    {
        long x1 = 2, x2 = 2, divisor;        
        if (N % 2 == 0) 
            return 2;
        do 
        {
            x1 = f(x1) % N;
            x2 = f(f(x2)) % N;
            divisor = gcd(Math.abs(x1 - x2), N);
        } while (divisor == 1);
        /** return divisor **/
        return divisor;
    }
    /** GCD of two numbers **/
    public  long gcd(long p, long q)
    {
        if (p % q == 0)
            return q;
        return gcd(q, p % q);
    }
    /** Check if num is prime **/
    public boolean isPrime(long N)
    {
        for (int i = 2; i <= Math.sqrt(N); i++)
            if (N % i == 0)
                return false;
        return true;
    }
    /** get all factors **/
    public void factor(long N) 
    {
        if (N == 1)
            return;
        if (isPrime(N)) 
        {
            //System.out.printf("%d ",N); 
	    Store[__num++]=N;
            return; 
        }
           long divisor = rho(N);
        factor(divisor);
        factor(N / divisor);
    }

	static BufferedInputStream in = new BufferedInputStream(System.in);
    static int readInt() {
        int no = 0;
        boolean minus = false;
        try {
            int a = in.read();
            while (a == 32 || a == 10) //10 is newline & 32 is ASCII for space
                a = in.read();
            if (a == '-') {
                minus = true;
                a = in.read();
            }
            while (a != 10 && a != 32 && a != -1) {
                no = no * 10 + (a - '0');
                a = in.read();
            }
        }catch (IOException e) {
            e.printStackTrace();
        }
        return minus ? -no: no;
    }
    static Long readLong() {
        Long no = 0L;
        boolean minus = false;
        try {
            int a = in.read();
            while (a == 32 || a == 10) //10 is newline & 32 is ASCII for space
                a = in.read();
            if (a == '-') {
                minus = true;
                a = in.read();
            }
            while (a != 10 && a != 32 && a != -1) {
                no = no * 10 + (a - '0');
                a = in.read();
            }
        }catch (IOException e) {
            e.printStackTrace();
        }
        return minus ? -no: no;
    }

    /** Main function **/
    public static void main(String[] args){
        
     	long T = readLong();
	while(--T>=0){
	        long N = readLong();
		if(N==1){
			System.out.printf("YES\n"); continue;
		}
		__num=0;
        		Main pr = new  Main();
        	pr.factor (N);
		//System.out.println();
		//for(int i=0;i<__num;i++)System.out.printf("%d ",Store[i]); System.out.printf("\n");
		Long ans=1L;
		for(int i=0;i<__num;){
			Long ct=0L,value=Store[i];
			while(i<__num && value==Store[i]) { i++;ct++;}
			ans=ans*(ct+1);		
		}
		if(ans%2==1) System.out.printf("YES\n");
		else System.out.printf("NO\n");
	}        
    }
}
