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
	static String readString() {
        StringBuilder str = new StringBuilder();
        try {
            int a = in.read();
            while (a == 32)
                a = in.read();
            while (a != 10 && a != 32 && a != -1) {
                str.append((char)a);
                a = in.read();
            }
        } catch(Exception e) {
            e.printStackTrace();
        }
        return str.toString();
    }

	public static void main(String[]args){
	
	    int D=readInt();
	    while(--D>=0){

		    String A=readString();
            int N=A.length();
            if(N==1){//No need of doing anything
                System.out.printf("NO\n");
            }else if(N%2==0){//both component should be equal 
                //otherwise answer will be no because only one operation permitted at most
                //if there are two more letter different than nothin can happen...so chill
                boolean ans=true;
                for(int i=0,j=N/2;i<N/2 && j<N;i++,j++){
                    if(A.charAt(i)!=A.charAt(j)){
                        ans=false;break;
                    }    
                }
                if(ans==true)System.out.printf("YES\n");
                else System.out.printf("NO\n");
            } else{
                //try to make two possible distribution
                //1). 0<=a<N/2 AND N/2<=b<N than culprit will be in second part
                //2).0<=a<=N/2 and N/2<b<N than culprit will be in first part

                //Part 1).0<=a<N/2 AND N/2<=b<N than culprit will be in second part
                int a=0,b=N/2;
                for(;a<N/2 && b<N;b++)
                    if(A.charAt(a)==A.charAt(b)) a++;
                b-=N/2;
                if( b-a <= 1 ){System.out.printf("YES\n");continue;}

                //Part 2).0<=a<=N/2 and N/2<b<N than culprit will be in first part
                a=0;b=(N/2+1);
                for(;a<=N/2 && b<N;a++)
                    if(A.charAt(a)==A.charAt(b)) b++;    
                b-=(N/2+1);    
                if( a-b <= 1 )System.out.printf("YES\n");
                else System.out.printf("NO\n");
            }
	   }
    }
}