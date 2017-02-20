/* package codechef; // don't place package name! */
import java.util.Scanner;
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;
import java.util.Scanner;
public class Main{

	public static void main(String[] args) {
		
		Scanner inp=new Scanner(System.in);
		int T;
		T=inp.nextInt();
		for(;T>0;T--){
			int n;
			n=inp.nextInt();
			long  [][] d=new long [n][2];
			for(int i=0;i<n;i++){

				d[i][0]=inp.nextLong();
				d[i][1]=inp.nextLong();
				if(d[i][1]==0) {
					d[i][0]=0;
				}
				else{
					d[i][0]*=d[i][1];
					--d[i][1];
				} 
			}
			Boolean flag=false;
			for(int i=0;i<n;i++){
				if(d[i][0]!=0){
					if(flag==true) System.out.printf(" + ");
					System.out.printf("%d",d[i][0]);
					if(d[i][1]!=0)
						System.out.printf("x^%d",d[i][1]);
					flag=true;
				}
			}
			if(flag==false) 
				System.out.printf("0");
			System.out.println();
		}
	}
}
