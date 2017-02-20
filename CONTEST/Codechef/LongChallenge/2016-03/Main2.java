/*
	RAMESH CHANDRA
	PRE-FINAL YEAR B.TECH
	NITK SURATHKAL
*/

import java.io.*;
import java.util.*;

public class Main{

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

	public static void main(String[]args){
	
	Scanner inp=new Scanner(System.in);
	int T=inp.nextInt();
		for(;T>0;T--){
			int N=inp.nextInt();
			Long K=inp.nextLong();
			Long []A=new Long[N];
			Long []B=new Long[N];
			Long sum=0L;//to hold sum without any change
			for(int i=0;i<N;i++)
				A[i]=inp.nextLong();
			for(int i=0;i<N;i++){
				B[i]=inp.nextLong();
				sum+=B[i]*A[i];//ADD TO SUM A[i]*B[i]
			}
			Long ans=sum;//answer without doing any change
			for(int i=0;i<N;i++){
				//System.out.printf("%d --> ",sum);
				sum-=(A[i]*B[i]);//remove part of current multiplication
				//System.out.printf("%d --> ",sum);
				sum+=Math.max( (A[i]+K)*B[i],(A[i]-K)*B[i]);//add or subtract by K THEN ADD TO SUM
				//System.out.printf("%d --> ",sum);
				ans=Math.max(ans,sum);//update with maximum possible value
				//System.out.printf("%d --> ",sum);
				sum-=Math.max( (A[i]+K)*B[i],(A[i]-K)*B[i]);//REVERSE OPERATION OF add or subtract by K
				//System.out.printf("%d --> ",sum);
				sum+=(A[i]*B[i]);//revert back original change without any change;
				//System.out.printf("%d\n",sum);
			}
			System.out.printf("%d\n",ans);//give final ans to judge
		}	
	}
}
