import java.util.Scanner;
public class Main{
	public static void main(String []args){
		Scanner in=new Scanner(System.in);
		String s = new String();
		s=in.nextLine();
		int ab=0,ba=0;
		for(int i=0;i<s.length()-1;i+=2)
			if(s.charAt(i)=='A' && s.charAt(i+1)=='B') ab=1;
			else if(s.charAt(i)=='B' && s.charAt(i+1)=='A') ba=1;
		if(ab+ba==2) System.out.printf("YES\n");
		else System.out.printf("NO\n");	
	}
}