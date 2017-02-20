import java.io.*;
import java.util.*;
import java.math.*;
public class Solution2 {

    public static void main(String[] args) {

		Scanner inp=new Scanner(System.in);		
		int T;
		T=inp.nextInt();
		for(;T>0;T--){

			int N,L;
			N=inp.nextInt();
			L=inp.nextInt();
			int [] P = new int[N];
			int [] V = new int[N];
			for(int i=0;i<N;i++)
				P[i]=inp.nextInt();
			for(int i=0;i<N;i++)
				V[i]=inp.nextInt();
			double ans=0,check=0;
			for(int i=0;i<N;i++){
			
				if(V[i]>0)
					check=((double)L-(double)P[i])/(double)V[i];
				else
					check=-(double)L/(double)V[i];
				ans=Math.max(ans,check);
			}
			System.out.printf("%.9f\n",ans);
		}    
	}
}
