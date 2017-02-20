import java.util.*;
import java.io.*;
import java.math.*;
import java.util.Scanner;
public class Main{

	public static void main(String []args){
		Scanner in=new Scanner(System.in);
		int T=in.nextInt();
		long  N,D,C,ans;
		for(;T>0;T--){

			N=in.nextLong();
			D=in.nextLong();
			ans=0;
			for(;N>1;N--){
				C=in.nextLong();
				ans+=(C>D)?C-D:0;
				D=Math.min(C,D);
			}
			System.out.printf("%d\n",ans);
		}
	} 
}