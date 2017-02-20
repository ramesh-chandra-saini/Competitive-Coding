import java.util.String;
import java.util.Scanner;

public class Main{
	public static void main(String []args){
		Scanner in=new Scanner(System.in);
		String s = new String();
		s=in.nextString();
		int ab=0,ba=0;
		for(int i=0;i<s.length()-1;i+=2)
			if(s[i]=='A' && s[i+1]=='B') ab=1;
			else if(s[i]=='B' && s[i+1]=='A') ba=1;
		if(ab+ba==2) System.out.printf("YES\n");
		else System.out.printf("NO\n");	
	}
}