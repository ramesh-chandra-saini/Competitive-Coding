import java.io.*;
import java.util.*;
import java.math.*;
public class Solution {
    public static void main(String[] args) {
		Scanner inp=new Scanner(System.in);		
		int T;
		T=inp.nextInt();
		for(;T>0;T--){
			int N,MOD=1000000007;
			N=inp.nextInt();
			int []arr=new int[N+1];arr[0]=-1;
			for(int i=1;i<=N;i++)
				arr[i]=inp.nextInt();
			if(N==1){ System.out.printf("1\n"); continue;}
			long []dp=new long [N+1];
			dp[0]=0L;dp[1]=1L;dp[2]=(arr[1]==arr[2])?2L:3L;		
			for(int i=3;i<=N;i++)
			     dp[i]=(dp[i-1]+((arr[i]==arr[i-1])?0L:(dp[i-1]-dp[i-2]) )+((arr[i]==arr[i-2])?0L:(dp[i-2]-dp[i-3]))+1+MOD)%MOD;
			//for(int i=0;i<=N;i++)  System.out.printf("%d\t",dp[i]);
 			System.out.printf("%d\n",dp[N]);
		}    
	}
}
