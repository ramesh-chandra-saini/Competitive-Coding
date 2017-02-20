/*
	RAMESH CHANDRA
	PRE-FINAL YEAR B.TECH
	NITK SURATHKAL
*/

import java.io.*;
import java.util.*;

public class Main{

	public static void main(String[]args){
	   Scanner in=new Scanner(System.in);
	    int D=in.nextInt();
        in.nextLine();
	    while(--D>=0){

		    String A=in.nextLine();
            String B=in.nextLine();
            int []a=new int[26];
            int []b=new int[26];
            for(int i=0;i<26;a[i]=b[i++]=0);
            for(int i=0;i<A.length();i++)
                a[A.charAt(i)-'a']++;
            for(int i=0;i<B.length();i++)
                b[B.charAt(i)-'a']++;
            boolean ans=false;
            for(int i=0;i<26;i++)
                ans=(a[i]>0 && b[i]>0)?true:ans;       
            if(ans==true) System.out.printf("Yes\n");
            else System.out.printf("No\n");
        }
    }
}